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
#define get_value(type, node, name)              \
  ((type*)node->data)->name;

Node *create_node(void *data);

/// List
typedef struct List_t{
  struct Node_t *head;
} List;
List create_list();
int size(List*l);
Node *find(List*l, Node *value, compare comp);
Node* begin(List*l);
Node*next(Node*v);
void free_list(List *l);
void push_back(List *l, Node *node);
void push_front(List*l, Node *node);
//end list
