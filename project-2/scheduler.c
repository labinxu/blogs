#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "scheduler.h"


int process_sort(const void *pv1, const void *pv2){
  Process *p1 = (Process*)pv1;
  Process *p2 = (Process*)pv2;
  if(p1->arrived_time==p2->arrived_time){
    return p1->pid > p2->pid;
  }
  return p1->arrived_time > p2->arrived_time;
}

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

List init_processes(char* filename,int args){
  FILE* pf=fopen(filename,"r");
  List l=create_list();
  if(pf == NULL){
    printf("ERROR:%s\n",filename);
    return l;
  }

  int arrived,pid,mem,jobtime;
  while(fscanf(pf, "%d %d %d %d",&arrived,&pid,&mem,&jobtime)==args){
    Process *proc = create_process();
    proc->arrived_time=arrived;
    proc->pid=pid;
    proc->memory=mem;
    proc->jobtime=jobtime;
    list_push_back(&l, proc, sizeof(Process));
    free(proc);
    }
  fclose(pf);
  return l;
}
/* void ff(int time){ */
  
/* } */
/* void rr(int time){ */
  
/* } */
void Scheduling(){
    List procs=init_processes("process.txt",4);
    //
    //Node *active_proc=NULL;
    size_t elaspe=0;
    while(list_size(&procs)!=0){
      elaspe++;
      //process
    }
    free_list(&procs);
}
