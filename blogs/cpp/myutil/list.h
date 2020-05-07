#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define log(...) printf (__VA_ARGS__)
#define info(args...) printf("INFO:");printf(args);

typedef int (*compare)(const void *, const void *);


// Node
typedef struct Node_t{
  void *data;
  struct Node_t *next;
} Node;

void free_node(Node*n);
void free_node_with_data(Node *n);
#define get_value(type, node, name)              \
  ((type*)node->data)->name;

Node *create_node(void *data);

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
Node* begin(List*l);
Node* next(Node*v);
void free_list(List *l);
void free_list_with_data(List *l);
void* list_push_back(List *l, Node *node);
void list_push_front(List*l, Node *node);
//end list
