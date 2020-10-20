#ifndef types_h_
#define types_h_
#include "node.h"

#define FILE_NAME_MAX_LEN 53
#define BRANCH_NAME_MAX_LEN 20
#define COMMIT_ID_MAX_LEN 7

typedef enum ChangeType{e_add=1,e_modified,e_deleted} ChangeType;

typedef struct FileInfo{
  char filename[FILE_NAME_MAX_LEN];
  int hash;
} FileInfo;

FileInfo *create_fileinfo(void *helper, char *filename);
Node* make_fileinfo_node(char* filename);
void free_FileInfo(FileInfo *fi);

typedef struct File {
  char name[FILE_NAME_MAX_LEN];
} File;

File *create_file(char *filename);

typedef struct Change
{
  ChangeType changeType;
  char fileName[FILE_NAME_MAX_LEN];
  char *details;
} Change;


#endif
