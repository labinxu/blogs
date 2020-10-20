#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"

void free_node(Node*n){
  if(n){
    if(n->data)
      free(n->data);
    free(n);
  }
}

Node *create_node(void *data){
  Node *node =  (Node*)malloc(sizeof(Node));
  memset(node, 0, sizeof(Node));
  node->data=data;
  return node;
}

Node *find(List*l, Node *value, compare comp){

  Node*tmpn = l->head;
  while(tmpn){
    if(comp(value->data,tmpn->data)==0){
      return tmpn;
    }
    tmpn=tmpn->next;
  }
  return NULL;
}
////////// USER CODE//////////

/////
List create_list(){
  List l;
  memset(&l,0, sizeof(List));
  return l;
};

Node* begin(List*l){
  return l->head;
}

Node*next(Node*v){
  return v->next;
}

void free_list(List *l){
  Node tmpnode;
  tmpnode.next=l->head;
  while(tmpnode.next != NULL){
    Node *tmp=tmpnode.next;
    tmpnode.next = tmpnode.next->next;
    free_node(tmp);
  }
}

void push_back(List *l, Node *node){
  Node tmphead;
  memset(&tmphead,0,sizeof(Node));
  tmphead.next=l->head;
  Node *tmpnode=&tmphead;

  while(tmpnode->next != NULL){
    tmpnode=tmpnode->next;
  }
  tmpnode->next=node;
  l->head=tmphead.next;
}

void push_front(List*l, Node *node){
  node->next=l->head;
  l->head=node;
  l->head->next=NULL;
}
int size(List *l){
  int i=0;
  Node* iter=l->head;
  while(iter){
    i++;
    iter=next(iter);
  }
  return i;
}
/* int main_(){ */
/*   List l = create_list(); */
/*   Node *n = create_student("hubo", 1, 11, 22); */
/*   push_back(&l , n); */
/*   n = create_student("hubo1", 1, 111, 221); */
/*   push_back(&l , n); */
/*   n = create_student("hubo2", 2, 112, 222); */
/*   push_back(&l , n); */
/*   n = create_student("hubo3", 31, 113, 223); */
/*   push_back(&l , n); */
/*   n = create_student("hubo4", 43, 114, 224); */
/*   push_back(&l , n); */
/*   n = create_student("hubo5", 5, 115, 225); */
/*   push_back(&l , n); */

/*   Node findn; */
/*   findn.data="hubo3"; */
/*   Node*nn = find(&l, &findn, is_same_student); */
/*   if(nn){ */
/*     char *name = get_value(Student, nn, name); */
/*     int age = get_value(Student,nn,age); */
/*     int weight = get_value(Student, nn, weight); */
/*     int high = get_value(Student,nn,high); */
/*     log("%s,%d,%d,%d\n",name,age,weight,high); */
/*   } */
/*   Node *iter=begin(&l); */
/*   while(iter){ */
/*     char *name = get_value(Student, iter, name); */
/*     int age = get_value(Student,iter,age); */
/*     int weight = get_value(Student, iter, weight); */
/*     int high = get_value(Student,iter,high); */
/*     log("%s,%d,%d,%d\n",name,age,weight,high); */
/*     iter=next(iter); */
/*   } */
/*   free_list(&l); */
/*   return 0; */
/* } */
