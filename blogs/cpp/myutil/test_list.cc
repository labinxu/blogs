extern"C"{
#include "svc.h"
#include "list.h"
#include "types.h"
#include "vector.h"
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
TEST(test, TEST_VECTOR_MAKE_0){
  vector v=make_vector(sizeof(Student),1);
  Student s1;
  strcpy(s1.name,"boy1");
  s1.weight=100;
  s1.high = 120;
  s1.age = 11;
  vector_push_back(&v,&s1);
  EXPECT_EQ(vector_size(&v),1);
  Student s2;
  strcpy(s2.name,"boy2");
  s2.weight=100;
  s2.high = 120;
  s2.age = 11;
  vector_push_back(&v,&s2);
  EXPECT_EQ(vector_size(&v),2);
  auto ss = (Student*)vector_at(&v,0);
  EXPECT_EQ(strcmp(ss->name,"boy1"),0);

  Student *ps = (Student*)vector_at(&v,1);
  EXPECT_EQ(strcmp(ps->name,"boy2"),0);

  Student s3;
  strcpy(s3.name,"boy3");
  s3.weight=100;
  s3.high = 120;
  s3.age = 11;
  vector_push_back(&v,&s3);
  EXPECT_EQ(vector_size(&v),3);
  Student *ps3 = (Student*)vector_at(&v,2);
  EXPECT_EQ(strcmp(ps3->name,"boy3"),0);

  Student s4;
  strcpy(s4.name,"boy4");
  s4.weight=100;
  s4.high = 120;
  s4.age = 11;
  vector_push_back(&v,&s4);
  EXPECT_EQ(vector_size(&v),4);

  Student *ps4 = (Student*)vector_at(&v,3);
  EXPECT_EQ(strcmp(ps4->name,"boy4"),0);

  Student s5;
  strcpy(s5.name,"boy5");
  s5.weight=100;
  s5.high = 120;
  s5.age = 11;
  vector_push_back(&v,&s5);
  EXPECT_EQ(vector_size(&v),5);

  Student *ps5 = (Student*)vector_at(&v,4);
  EXPECT_EQ(strcmp(ps5->name,"boy5"),0);

  EXPECT_EQ(v.capbility , 8);
  EXPECT_EQ(v.iter, 5);

  // crack ps4 ,realloc
  Student *pf = (Student*)vector_find(&v, ps5, is_same_student);
  EXPECT_EQ(strcmp(pf->name,"boy5"),0);

  Student *pn = (Student*)vector_remove(&v,0);
  EXPECT_EQ(strcmp(pn->name,"boy2"),0);
  EXPECT_EQ(vector_size(&v),4);

  pn = (Student*)vector_remove(&v,0);
  EXPECT_EQ(strcmp(pn->name,"boy3"),0);
  EXPECT_EQ(vector_size(&v),3);

  pn = (Student*)vector_remove(&v,0);
  EXPECT_EQ(strcmp(pn->name,"boy4"),0);
  EXPECT_EQ(vector_size(&v),2);

  pn = (Student*)vector_remove(&v,0);
  EXPECT_EQ(strcmp(pn->name,"boy5"),0);
  EXPECT_EQ(vector_size(&v),1);
  pn = (Student*)vector_remove(&v,0);
  EXPECT_EQ(strcmp(pn->name,"boy5"),-1);
  EXPECT_EQ(vector_size(&v),0);

  vector_free(&v);
}

TEST(test, TEST_ARRAY_1){
  // vector v = create_vector();
  // vector_free(&v);

  // vector vv = create_vector(10);
  // char*p=(char*)malloc(sizeof(char)*20);
  // strcpy(p, "hello world");
  // vector_push_back(&vv, p);
  // int ret = strcmp((char*)vector_at(&vv,0), "hello world");
  // EXPECT_EQ(ret,0);
  // vector_free(&vv);
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
int comparefile(const void*a, const void*b){
  return strcmp(((FileInfo*)a)->filename, ((FileInfo*)b)->filename);
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
 
  Node* it = list_find(&l,tmpnode,comparefile);

  EXPECT_NE(it,nullptr);
  EXPECT_EQ( strcmp( ((FileInfo*)(tmpnode->data))->filename, "firstfile2.py"),0);
  l=list_reverse(&l);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile2.py"),0);

  l=list_reverse(&l);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile.py"),0);
  free_node(tmpnode);

  list_remove(&l, &fi, comparefile);
  EXPECT_EQ(list_size(&l), 1);
  EXPECT_EQ( strcmp( ((FileInfo*)(l.head->data))->filename, "firstfile2.py"),0);

  free_list(&l);
}
TEST(test, TEST_LIST_3){
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

  FileInfo fi3;
  memset(&fi3, 0, sizeof(FileInfo));
  strcpy(fi3.filename, "firstfile3.py");

  Node* tmpnode =make_node(&fi,sizeof(fi));
  Node* it = list_find(&l,tmpnode,comparefile);
  if(it){
    Node *newnode = make_node(&fi3,sizeof(FileInfo));
    newnode->next=it->next;
    it->next=newnode;
    EXPECT_EQ(3, list_size(&l));
  }
  it = l.head;
  EXPECT_EQ(0, strcmp((char*)it->data,"firstfile.py"));
  it = list_next(it);
  EXPECT_EQ(0, strcmp((char*)it->data,"firstfile3.py"));
  it = list_next(it);
  EXPECT_EQ(0, strcmp((char*)it->data,"firstfile2.py"));

  free_node(tmpnode);
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
