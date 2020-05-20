#ifndef TYPES_H
#define TYPES_H
#include<string.h>
#include<stdlib.h>
typedef struct Process{
  int arrived_time;
  int pid;
  int memory;
  int jobtime;
  int status; //0 created,1 running,2 suspended,3 completed
} Process;

Process *create_process(){
  Process *p = (Process*)malloc(sizeof(Process));
  memset(p,0,sizeof(Process));
  return p;
}
void process_terminal(Process *p){
  p->status = 3;
}
void process_start(Process *p){
  p->status=1;
}
void process_pause(Process *p){
  p->status=2;
}

#endif
