#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "scheduler.h"

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
    //printf("%d,%d,%d,%d\n", arrived,pid,mem,lifetime);
    }
  fclose(pf);

  return l;
}
void ff(int time){
  
}
void rr(int time){
  
}
void Scheduling(){
    List procs=init_processes("process.txt",4);
    //
    Node *active_proc=NULL;
    size_t elaspe=0;
    while(list_size(&procs)!=0){
      elaspe++;
      //process
      
    }
    free_list(&procs);
}
