#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"


Node *list_find(List*l, Node *value, compare comp){

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

List create_list(){
  List l;
  memset(&l,0, sizeof(List));
  return l;
};

Node* begin(List*l){
  return l->head;
}

Node*list_next(Node*v){
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
void free_list_with_data(List *l){
  Node tmpnode;
  tmpnode.next=l->head;
  while(tmpnode.next != NULL){
    Node *tmp=tmpnode.next;
    tmpnode.next = tmpnode.next->next;
    free_node(tmp);
  }
}
void *list_push_back(List *l,void *d, size_t size )
{
  Node tmphead;
  Node *node = make_node(d, size);
  memset(&tmphead,0,sizeof(Node));
  tmphead.next=l->head;
  Node *tmpnode=&tmphead;

  while(tmpnode->next != NULL){
    tmpnode=tmpnode->next;
  }
  tmpnode->next=node;
  l->head=tmphead.next;
  return tmpnode->next;

}
/* void* list_push_back(List *l, Node *node){ */
/*   Node tmphead; */
/*   memset(&tmphead,0,sizeof(Node)); */
/*   tmphead.next=l->head; */
/*   Node *tmpnode=&tmphead; */

/*   while(tmpnode->next != NULL){ */
/*     tmpnode=tmpnode->next; */
/*   } */
/*   tmpnode->next=node; */
/*   l->head=tmphead.next; */
/*   return node; */
/* } */

void* list_push_front(List*l, Node *node){
  node->next=l->head;
  l->head=node;
  l->head->next=NULL;
  return node;
}

List list_reverse(List *l){
  Node *pre=NULL;
  Node *next=NULL;
  Node *head = l->head;
  while(head){
    next = head->next;
    head->next=pre;
    pre=head;
    head = next;
  }
  l->head = pre;
  return *l;
}

void list_remove(List *l, void *data, compare comp){

  Node* tmpn=(Node*)malloc(sizeof(Node));
  memset(tmpn,0,sizeof(Node));
  tmpn->next = l->head;
  l->head = tmpn;
  Node *n = tmpn->next;
  Node *pre = tmpn;
  while(n){
    if(comp(data, n->data)==0){
      pre->next = n->next;
      free_node(n);
      break;
    }
    pre = n;
    n = n->next;
  }
  l->head = l->head->next;
  free_node(tmpn);
}

int list_size(List *l){
  int i=0;
  Node* iter=l->head;
  while(iter){
    i++;
    iter=list_next(iter);
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
