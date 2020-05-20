extern"C"{
#include "list.h"
#include "types.h"
#include "scheduler.h"
}
#include <gtest/gtest.h>
#include<string.h>
#include <string>

typedef struct Student_t{
  char name[10];
  int age;
  int weight;
  int high;
}Student;

extern "C" int is_same_student(const void*s1, const void*s2){
  return strcmp(((Student*)s1)->name , ((Student*)s2)->name);
}

extern "C" Student* create_student(const char*name,int age, int weight,int high){
  Student *s = (Student*)malloc(sizeof(Student));
  strcpy(s->name,name);
  s->age=age;
  s->high=high;
  s->weight=weight;
  return s;
}
Node *make_student_node(const char *name , int age, int weight, int high){
  Student s;
  strcpy(s.name,name);
  s.age=age;
  s.high=high;
  s.weight=weight;
  return make_node(&s,sizeof(Student));
}

extern "C" void free_student(Student *s){
  if(s)
    free(s);
}
 
TEST(test, TEST_CREATE_NODE){
    char *data=(char*)malloc(12);
    memset(data,0,12);
    strcpy(data,"hello world");
    Node *node = make_node(data,12);
    EXPECT_EQ(strcmp("hello world",(char*)node->data),0);
    free_node(node);
    free(data);
}

int comparefile(const void*a, const void*b){
  return 0;
}

TEST(test, TEST_INIT_PROCESS){
  List procs=init_processes((char*)"process.txt",4);
  //
  free_list(&procs);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
