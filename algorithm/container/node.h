#ifndef node_h
#define node_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define get_value(type, node, name)             \
  ((type*)node->data)->name;

// Node
typedef struct Node_t{
  void *data;
  struct Node_t *next;
} Node;


void free_node(Node*n);
void free_node_with_data(Node *n);
Node *make_node(void *data, size_t datasize);
Node *create_node(void *data);


#endif
