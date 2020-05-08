extern"C"{
#include "svc.h"
#include "list.h"
#include "types.h"
}
#include<string>
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
    Node *node = make_node(data,12);
    EXPECT_EQ(strcmp("hello world",(char*)node->data),0);
    free_node(node);
    free(data);
}

TEST(test ,TEST_MAKE_FILEINFO){
  FileInfo fi;
  strcpy(fi.filename, "firstfile.py");
  Node *node = make_node(&fi,sizeof(FileInfo));
  free_node(node);
}

TEST(test ,TEST_MAKE_FILE){
  File file;
  strcpy(file.name, "firstfile.py");
  List l = create_list();
  list_push_back(&l, &file, sizeof(File));
  EXPECT_EQ(list_size(&l),1);

  free_list(&l);
}

TEST(test ,TEST_LIST_1){
  FileInfo fi;
  strcpy(fi.filename, "firstfile.py");
  List l = create_list();
  EXPECT_EQ(0,list_size(&l));
  list_push_back(&l,&fi, sizeof(FileInfo));
  EXPECT_EQ(1,list_size(&l));
  free_list(&l);
}

TEST(test ,TEST_LIST_2){
  List l = create_list();

  FileInfo fi;
  memset(&fi, 0, sizeof(FileInfo));
  strcpy(fi.filename, "firstfile.py");

  list_push_back(&l,&fi, sizeof(FileInfo));
  FileInfo fi2;
  memset(&fi2, 0, sizeof(FileInfo));
  strcpy(fi2.filename, "firstfile2.py");
  list_push_back(&l,&fi2, sizeof(FileInfo));

  EXPECT_EQ(2,list_size(&l));

  Node* tmpnode =make_node(&fi2,sizeof(fi2));
  auto comp = [](const void *a,const void *b)->int{
                return strcmp(((FileInfo*)a)->filename, ((FileInfo*)b)->filename);
                 };
  Node* it = list_find(&l,tmpnode,comp);

  EXPECT_EQ( strcmp( ((FileInfo*)(tmpnode->data))->filename, "firstfile2.py"),0);
  l=list_reverse(&l);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile2.py"),0);

  l=list_reverse(&l);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile.py"),0);
  free_node(tmpnode);

  list_remove(&l, &fi, comp );
  EXPECT_EQ(list_size(&l), 1);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile2.py"),0);

  free_list(&l);
}

// TEST(test, TEST_SVC_INIT){
//     void *helper = svc_init();
//     cleanup(helper);
//  }


// TEST(test, TEST_SVC_ADD1){
//    void *helper = svc_init();
//    int a = svc_add(helper,(char*)"hello.py");
//    EXPECT_EQ(a, -2);
//    a = svc_add(helper, (char*)"unittest/hello.py");
//    EXPECT_NE(2,a);
//    a = svc_add(helper, (char*)"unittest/hello.py");
//    EXPECT_EQ(-2,a);

//    cleanup(helper);
// }

// TEST(test, TEST_SVC_COMMIT1){
//   void *helper = svc_init();
//   int a = svc_add(helper, (char*)"unittest/hello.py");
//   EXPECT_NE(2,a);
//   //svc_commit();

//   cleanup(helper);
// }

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
