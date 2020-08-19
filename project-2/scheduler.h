#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list.h>
typedef struct Process{
  int arrived_time;
  int pid;
  int memory;
  int jobtime;
  int status; //0 created,1 running,2 suspended,3 completed
} Process;
List init_processes(char* filename,int args);
int process_sort(const void*pv1, const void*pv2);
#endif
