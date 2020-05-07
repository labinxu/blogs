extern"C"{
#include "svc.h"
#include "list.h"
}
#include<string>
#include <gtest/gtest.h>
#include<string.h>

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
extern "C" void free_student(Student *s){
  if(s)
    free(s);
}

// TEST(test, TEST_PUSH_BACK_SIZE){
//   List l = create_list();
//   EXPECT_EQ(0,list_size(&l));
//   Student *s = create_student("hubo", 1, 11, 22);
//   list_push_back(&l , create_node(s));
//   EXPECT_EQ(list_size(&l),1);
//   free_list(&l);
//   free_student(s);
// }

TEST(test, TEST_CREATE_NODE){
    char *data=(char*)malloc(12);
    memset(data,0,12);
    strcpy(data,"hello world");
    Node *node = create_node(data);
    EXPECT_EQ(strcmp("hello world",(char*)node->data),0);
    free_node_with_data(node);
}

TEST(test, TEST_SVC_INIT){
    void *helper = svc_init();
    cleanup(helper);
 }


TEST(test, TEST_SVC_ADD1){
   void *helper = svc_init();
   int a = svc_add(helper,(char*)"hello.py");
   EXPECT_EQ(a, -2);
   a = svc_add(helper, (char*)"unittest/hello.py");
   EXPECT_NE(2,a);
   a = svc_add(helper, (char*)"unittest/hello.py");
   EXPECT_EQ(-2,a);

   cleanup(helper);
}

TEST(test, TEST_SVC_COMMIT1){
  void *helper = svc_init();
  int a = svc_add(helper, (char*)"unittest/hello.py");
  EXPECT_NE(2,a);
  //svc_commit();

  cleanup(helper);
}

// int _main(){
//   List l = create_list();
//   Student *s = create_student("hubo", 1, 11, 22);
//   list_push_back(&l , create_node(s));
//   s = create_student("hubo1", 1, 111, 221);
//   list_push_back(&l , create_node(s));
//   free_student(s);
//   // n = create_student("hubo2", 2, 112, 222);
//   // list_push_back(&l , n);
//   // n = create_student("hubo3", 31, 113, 223);
//   // list_push_back(&l , n);
//   // n = create_student("hubo4", 43, 114, 224);
//   // list_push_back(&l , n);
//   // n = create_student("hubo5", 5, 115, 225);
//   // list_push_back(&l , n);

//   Node findn;
//   findn.data=(void*)std::string("hubo3").data();
//   Node*nn = list_find(&l, &findn, is_same_student);
//   if(nn){
//     char *name = get_value(Student, nn, name);
//     int age = get_value(Student,nn,age);
//     int weight = get_value(Student, nn, weight);
//     int high = get_value(Student,nn,high);
//     log("%s,%d,%d,%d\n",name,age,weight,high);
//   }
//   Node *iter=begin(&l);
//   while(iter){
//     char *name = get_value(Student, iter, name);
//     int age = get_value(Student,iter,age);
//     int weight = get_value(Student, iter, weight);
//     int high = get_value(Student,iter,high);
//     log("%s,%d,%d,%d\n",name,age,weight,high);
//     iter=next(iter);
//   }
//   free_list(&l);
//   return 0;
// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
