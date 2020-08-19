#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun(int*,int*);
typedef struct node{
  char *word;
  struct node * next;
} node;
node *remove_front(node **head);
int main(){

  int i=5,j=2;
  fun(&i,&j);
  printf("%d,%d\n", i,j);

  unsigned int a=0xffff;
  printf("%x\n", a);
  a=~a;
  printf("%x\n", a);

  int *p;
  p=(int*)malloc(128);
  printf("%d\n", sizeof(p));
  free(p);

  double *pp;
  pp=(double*)malloc(128);
  printf("%d\n", sizeof(pp));
  free(pp);
  printf("%d,%d\n",sizeof(int),sizeof(double));

  node *node1 = (node*)malloc(sizeof(node));
  node1->word = (char*)malloc(20);
  strcpy(node1->word, "node1");

  node *node2 = (node*)malloc(sizeof(node));
  node2->word = (char*)malloc(20);
  strcpy(node2->word, "node2");

  node *node3 = (node*)malloc(sizeof(node));
  node3->word = (char*)malloc(20);
  strcpy(node3->word, "node3");

  node1->next=node2;
  node2->next=node3;
  node3->next=NULL;
  node *pret= remove_front(&node1);
  printf("%s\n", pret->word);

  int x = 0xA3C9871B;
  x=x|(0xFF <<8);
  printf("%x\n",x);

  printf("x^x = %x\n", x^x);
  int b = 0xF000000F;
  printf("%x\n", b>>2);

  printf("%d\n", 7>>2);//1
  printf("%d\n", 7<<1);//14
  printf("%d\n", 7|2);//7
  printf("%d\n", 7&&0);//0


  printf("double sizeof %d\n", sizeof(double));
  printf("int sizeof:%d\n",sizeof(int));
  return 0;
}

void fun(int *i , int *j){
  *i = *i+*j;
  *j = *i+*j;
}


node *remove_front(node **head){
  if(head == NULL){
    return NULL;
  }
  node *ptmp = *head;
  *head = (*head)->next;

  return ptmp;
}

void split(int v){
  int m = 1;
  int a=0;
  int b=0;
  for(int i=0;i<64;i++){
    m = m<<i;
    int tmpk = v&m;
    if(i%2==0){
      a |= tmpk;
    }
    else{
      b |= tmpk;
    }
  }
}
