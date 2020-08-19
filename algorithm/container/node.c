#include "node.h"


Node *make_node(void *data, size_t datasize){
  Node *node = (Node*)malloc(sizeof(Node));
  memset(node , 0, sizeof(Node));
  node->data = malloc(datasize);
  memcpy(node->data, data, datasize);
  return node;
}

void free_node_without_data(Node*n){
  if(n){
    free(n);
  }
}

void free_node(Node *n){
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
