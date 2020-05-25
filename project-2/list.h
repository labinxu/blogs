#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"

#define log(...) printf (__VA_ARGS__)
#define info(args...) printf("INFO:");printf(args);




/// List
typedef struct List_t{
  struct Node_t *head;
} List;

#define FREE_LIST(nodeType,l)\
  Node tmpnode;\
  tmpnode.next=l->head;\
  while(tmpnode.next != NULL){\
  Node *tmp=tmpnode.next;\
  tmpnode.next = tmpnode.next->next;\
  free_##nodeType((nodeType*)tmp->data);\
  free_node(tmp);}

List create_list();
int list_size(List*l);
Node *list_find(List*l, Node *value, compare comp);
Node* list_begin(List*l);
Node* list_next(Node*v);
void list_sort(List *l,compare comp);
void free_list(List *l);
void free_list_with_data(List *l);
void list_remove(List *l, void *value,compare comp);
void* list_push_front(List*l, Node *node);
void* list_push_back(List *l, void *node, size_t size);
List list_reverse(List *l);
//end list
#endif
