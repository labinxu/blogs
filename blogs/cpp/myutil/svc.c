#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/dir.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include "list.h"
#include "svc.h"
#include "types.h"


FileInfo *create_fileinfo(void *helper, char *filename){
  FileInfo *fi=(FileInfo*)malloc(sizeof(FileInfo));
  memset(fi, 0, sizeof(FileInfo));
  strncpy(fi->filename, filename, FILE_NAME_MAX_LEN);

  fi->hash = hash_file(helper, filename);
  return fi;
}

void free_FileInfo(FileInfo *fi){
  if(fi)
    free(fi);
}

Node *make_fileinfo_node(char *filename){
  FileInfo fi;
  strcpy(fi.filename,filename);
  return make_node(&fi, sizeof(FileInfo));
}

Change* create_change(ChangeType ct,char *filename, char*comments){
  Change *pCh = (Change*)malloc(sizeof(Change));
  memset(pCh, 0, sizeof(Change));
  pCh->changeType = ct;
  strncpy(pCh->fileName,filename,FILE_NAME_MAX_LEN);
  if(comments){
    pCh->details = (char*)malloc(strlen(comments)+1);
    strcpy(pCh->details, comments);
  }
  return pCh;
}

void free_change(Change *change){
  if(change == NULL){
    return;
  }
  if(change->details){
    free(change->details);
  }
  free(change);
}

void free_changes(List *l){
  Node tmpnode;
  tmpnode.next=l->head;
  while(tmpnode.next != NULL){
    Node *n=(Node*)tmpnode.next;
    Change *change=(Change*)n->data;
    tmpnode.next = tmpnode.next->next;
    free_node(n);
    free_change(change);

  }
}

typedef struct Commit
{
    char commit_id[COMMIT_ID_MAX_LEN];
    char *message;
    List changes;
} Commit;

Commit* create_commit(char *commitid,char *message,List *change){
  if(message == NULL){
    return NULL;
  }
  Commit *pCmt = (Commit*)malloc(sizeof(Commit));
  strncpy(pCmt->commit_id, commitid, COMMIT_ID_MAX_LEN);
  pCmt->message = (char*)malloc(strlen(message)+1);
  strncpy(pCmt->message, message, strlen(message)+1);
  if(change){
    pCmt->changes = *change;
  }
  else{
    pCmt->changes =create_list();
  }
  return pCmt;
}

void free_commit(Commit *commit){
  if(commit->message){
    free(commit->message);
  }
  // free change
  free_changes(&(commit->changes));
  free(commit);
}

void free_commites(List* l){
  if(l == NULL){
    return;
  }
  Node tmpnode;
  tmpnode.next=l->head;
  while(tmpnode.next != NULL){
    Commit *commit=(Commit*)tmpnode.next->data;
    tmpnode.next = tmpnode.next->next;
    free_commit(commit);
  }
}

typedef struct Branch
{
  char name[BRANCH_NAME_MAX_LEN];
  List commits;
  List tracked;
} Branch;

void free_tracked(List *l){
  if(l == NULL){
    return;
  }
  FREE_LIST(FileInfo, l);
}

void free_Branch(Branch*b){
  free_commites(&(b->commits));
  free_tracked(&(b->tracked));
  free(b);
}

void free_branches(List *branches){

  if(branches == NULL){
    return;
  }
  FREE_LIST(Branch, branches);
  /* Node tmpnode; */
  /* tmpnode.next=branches->head; */
  /* while(tmpnode.next != NULL){ */
  /*   Node *n = (Node*)tmpnode.next; */
  /*   Branch *branch=(Branch*)n->data; */
  /*   tmpnode.next = tmpnode.next->next; */
  /*   free_branch(branch); */
  /*   free_node(n); */
  /* } */
}

typedef struct Helper
{
  List branches;
  List changes;
  Branch *HEAD;
} Helper;

Helper *create_helper(){
  Helper *helper = (Helper*)malloc(sizeof(Helper));
  memset(helper, 0, sizeof(Helper));
  helper->branches = create_list();
  return helper;
}
void free_helper(Helper *helper){
  if(helper){
    free_branches(&(helper->branches));
    free(helper);
  }

}
Branch *create_branch(void *helper, char *branchname){
  Branch *pBranch = (Branch*)malloc(sizeof(Branch));
  memset(pBranch, 0, sizeof(Branch));
  strncpy(pBranch->name, branchname, BRANCH_NAME_MAX_LEN);
  Helper *tmphelper = (Helper*)helper;
  list_push_back(&(tmphelper->branches), pBranch, sizeof(Branch));
  return pBranch;
}


int hash_file(void *helper, char *file_path)
{
  (void)helper;
  if (file_path == NULL)
    return -1;
  struct stat stat_buf;

  if (lstat(file_path, &stat_buf) < 0)
    return -2;
  if (0 == S_ISREG(stat_buf.st_mode))
    return -2;

  long int hash = 0;
  for (size_t i = 0; i < strlen(file_path); i++)
    hash = (hash + file_path[i]) % 1000;

  FILE *inputFile;
  inputFile = fopen(file_path, "rb");
  if (!inputFile)
    return -2;

  int ch;
  while ((ch = fgetc(inputFile)) != EOF)
    hash = (hash + ch) % 2000000000;

  fclose(inputFile);
  return hash;
}

void *svc_init(void){
  /* if(access(".svc", F_OK) == 0){ */
  /*   return NULL; */
  /* } */
  Helper *helper = create_helper();
  // init master
  //
  helper->HEAD = create_branch(helper, "master");
  //list_push_back(&(helper->branches), create_node(helper->HEAD));
  return helper;
}
int is_tracked(const void*s1, const void*s2){
  return strcmp((const char*)s1 , (const char*)s2);
}

int svc_add(void *helper, char *file_name)
{
  if(helper == NULL || file_name == NULL){
    return -1;
  }

  if(access(file_name, F_OK) != 0){
    return -2;
  }

  Helper *pHelper = (Helper*)helper;
  Branch *pbranch = pHelper->HEAD;
  FileInfo *fileinfo = create_fileinfo(helper, file_name);
  Node tmpn;
  tmpn.data=file_name;
  Node* node = list_find(&(pbranch->tracked),&tmpn,is_tracked);
  if(node == NULL){
  }
  else{
    free_FileInfo(fileinfo);
    return -2;
  }
  return fileinfo->hash;
}

char* svc_commit(void *helper, char *message){
  //Commit *pCmt=create_commit("", message, );
  if(helper == NULL || message == NULL){
    return NULL;
  }
  return NULL;
}

void cleanup(void *helper){
  Helper *phelper = (Helper*)helper;
  free_helper(phelper);
}
