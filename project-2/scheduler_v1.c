#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#define max_length 31
char filename[max_length], scheduling_algorithm[max_length], memory_allocation[max_length];
long long memory_size, quantum;

long long current_time = 0;
long long memory[1<<20]; // store the corresponding process id, value -1 for idle
long long memory_stamp[1<<20]; // store allocate index stamp. used for fifo page replacement algorithm
long long currnet_stamp = 0; // used for memory_stamp to store index stamp

struct process {
    long long time_arrived;
    long long time_finished;
    long long process_id;
    long long memory_size_require;
    long long job_time;
    long long remaining_time;
    long long time_stamp; // store the timestamp of the last operation， used for find the LRU process
    struct process *next;
};
struct process *head; // store all processes as list

void add_process(struct process *new_process) {
    // add process to list, sorted by time_arrived and process_id
    if (head == NULL) {
        head = new_process;
        return;
    }
    struct process *tail;
    for (tail = head; tail->next != NULL; tail = tail->next) {
        if (tail->next->time_arrived == new_process->time_arrived && tail->next->process_id > new_process->process_id) {
            break;
        }
    }
    new_process->next = tail->next;
    tail->next = new_process;
}


void read_processes() {
    // read processes file
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL) {
        printf("Wrong read");
        exit(0);
    }
    long long time_arrived, process_id, memory_size_require, job_time;
    while(fscanf(fp, "%lld%lld%lld%lld", &time_arrived, &process_id, &memory_size_require, &job_time) != EOF) {
        struct process *new_process = malloc(sizeof(struct process));
        memset(new_process, 0, sizeof(struct process));
        new_process->time_arrived = time_arrived;
        new_process->time_stamp = time_arrived;
        new_process->process_id = process_id;
        new_process->memory_size_require = memory_size_require / 4;
        new_process->job_time = job_time;
        new_process->remaining_time = job_time;
        add_process(new_process);
    }
    fclose(fp);
}

struct process *next_process() {
    // find the next process to execute
    if (strcmp(scheduling_algorithm, "ff") == 0) {
        for (struct process *tail = head; tail != NULL; tail = tail->next) {
            if (tail->remaining_time != 0) {
                return tail;
            }
        }
    }

    if (strcmp(scheduling_algorithm, "cs") == 0) {
        long long min_remaining_time = INT_MAX;
        for (struct process *tail = head; tail != NULL; tail = tail->next) {
            if (tail->remaining_time != 0 && tail->time_arrived <= current_time && tail->remaining_time < min_remaining_time) {
                min_remaining_time = tail->remaining_time;
            }
        }
        if (min_remaining_time != INT_MAX) {
            for (struct process *tail = head; tail != NULL; tail = tail->next) {
                if (tail->remaining_time != 0 && tail->time_arrived <= current_time && tail->remaining_time == min_remaining_time) {
                    return tail;
                }
            }
        }
        else {
            for (struct process *tail = head; tail != NULL; tail = tail->next) {
                if (tail->remaining_time != 0) {
                    return tail;
                }
            }
        }
    }

    if (strcmp(scheduling_algorithm, "rr") == 0) {
        long long min_time_stamp = INT_MAX;
        struct process *tail = head;
        for (struct process *tail = head; tail != NULL; tail = tail->next) {
            if (tail->remaining_time != 0 && tail->time_stamp < min_time_stamp) {
                min_time_stamp = tail->time_stamp;
            }
        }
        for (struct process *tail = head; tail != NULL; tail = tail->next) {
            if ((tail->remaining_time != 0) && (tail->time_stamp == min_time_stamp) && (tail->time_arrived == min_time_stamp)) {
                return tail;
            }
        }
        for (struct process *tail = head; tail != NULL; tail = tail->next) {
            if ((tail->remaining_time != 0) && (tail->time_stamp == min_time_stamp)) {
                return tail;
            }
        }
    }
    return NULL;
}

long long process_remaining() {
    // calculate the number of remaining processes
    int count = 0;
    for (struct process *tail = head; tail != NULL; tail = tail->next) {
        count += (tail->remaining_time != 0 && tail->time_arrived <= current_time);
    }
    return count;
}

long long memory_remaining() {
    // calculate the number of remaining momory pages
    int count = 0;
    for (int i = 0; i < memory_size; i++) {
        count += (memory[i] == -1);
    }
    return count;
}

long long memory_usage() {
    // calculate the usage of mempry
    return 100 - memory_remaining() * 100 / memory_size;
}

void deallocate_print() {
    // print deallocated memories
    int needed = 0;
    for (long long i = 0; i < memory_size; i++) {
        if (memory[i] == -2) {
            needed = 1;
        } 
    }
    if (needed == 0) {
        return;
    }

    printf("%lld, EVICTED, mem-addresses=[", current_time);
    int flag = 0;
    for (long long i = 0; i < memory_size; i++) {
        if (memory[i] == -2) {
            if (flag == 0) {
                flag = 1;
            }
            else {
                printf(",");
            }
            printf("%lld", i);
            memory[i] = -1;
        }
    }
    printf("]\n");
}

long long deallocate(struct process *current_process, long long size) {
    // deallocate current_process's momory pages, up to 'size' pages. If size equals\
    zero, deallocate all of its pages.
    long long count = 0;
    for (int i = 0; i < memory_size && (size == 0 || count != size); i++) {
        if (memory[i] == current_process->process_id) {
            memory[i] = -2;
            count++;
        }
    }
    return count;
}

long long deallocate_cm_fetch_index() {
    // fetch the first page's index
    long long min_stamp = INT_MAX, min_index = 0;
    for (long long i = 0; i < memory_size; i++) {
        if (memory[i] >= 0 && memory_stamp[i] < min_stamp) {
            min_stamp = memory_stamp[i];
            min_index = i;
        }
    }
    return min_index;
}

long long deallocate_cm(long long size) {
    // dealocate size memory pages using fifo
    for (long long i = 1; i <= size; i++) {
        memory[deallocate_cm_fetch_index()] = -2;
    }
    return size;
}

int memory_existed(struct process *current_process) {
    // judge whether current_process's pages existed in momory
    for (long long i = 0; i < memory_size; i++) {
        if (memory[i] == current_process->process_id) {
            return 1;
        }
    }
    return 0;
}

long long allocate(struct process *current_process) {
    // allocate pages for current_process
    long long memory_exist = 0;
    for (int i = 0; i < memory_size; i++) {
        memory_exist += (memory[i] == current_process->process_id);
    }
    long long memory_need;
    if (strcmp(memory_allocation, "cm") == 0) {
        memory_need = MIN(4, current_process->memory_size_require) - memory_exist;
    }
    else {
        memory_need = current_process->memory_size_require - memory_exist;
    }
    if (memory_remaining() < memory_need && strcmp(memory_allocation, "p") != 0) {
        memory_need = memory_remaining();
        if (memory_need + memory_exist < 4 && memory_need + memory_exist < current_process->memory_size_require) {
            memory_need = MIN(current_process->memory_size_require, 4) - memory_exist;
        }
    }
    long long memory_allocate = MAX(0, memory_need - memory_remaining());
    if (strcmp(memory_allocation, "cm") == 0) {
        memory_allocate -= deallocate_cm(memory_allocate);
    }
    else {
        for (int time = 0; memory_allocate > 0 && time <= current_time; time++) {
            struct process *tail;
            for (tail = head; tail != NULL; tail = tail->next) {
                if (tail->remaining_time != 0 && tail->time_stamp == time && tail->time_arrived != tail->time_stamp) {
                    break;
                }
            }
            if (tail && tail->remaining_time != 0 && tail->time_stamp == time && tail->time_arrived != tail->time_stamp) {
                if (strcmp(memory_allocation, "v") == 0) {
                    memory_allocate -= deallocate(tail, memory_allocate);
                }
                
                else {
                    memory_allocate -= deallocate(tail, 0);
                }
            }
        }
    }
    deallocate_print();
    long long load_time = memory_need * 2;
    current_process->remaining_time += current_process->memory_size_require - memory_exist - memory_need;
    for (int i = 0; i < memory_size && memory_need != 0; i++) {
        if (memory[i] == -1) {
            memory_stamp[i] = currnet_stamp++;
            memory[i] = current_process->process_id;
            memory_need -= 1;
        }
    }
    return load_time;
}

void print_memory(struct process *current_process) {
    // print the momory used for current_process
    int flag = 0;
    for (int i = 0; i < memory_size; i++) {
        if (memory[i] == current_process->process_id) {
            if (flag == 0) {
                flag = 1;
            }
            else {
                printf(",");
            }
            printf("%d", i);
        }
    }
}

void schedule() {
    // used for schedule
    struct process *current_process;
    while ((current_process = next_process()) != NULL) {
        
        if (current_time < current_process->time_arrived) {
            current_time = current_process->time_arrived;
        }

        current_process->time_stamp = INT_MAX; // mark it as running


        long long load_time = 0;
        if (strcmp(memory_allocation, "u") != 0) {
           load_time = allocate(current_process);
        }
        
        printf("%lld, RUNNING, id=%lld, remaining-time=%lld",\
         current_time, current_process->process_id, current_process->remaining_time);
        
        if (strcmp(memory_allocation, "u") != 0) {
            printf(", load-time=%lld, mem-usage=%lld%%, mem-addresses=[", load_time, memory_usage());
            print_memory(current_process);
            printf("]");
        }
        printf("\n");
        current_time += load_time;
        int running_time = current_process->remaining_time;
        if (strcmp(scheduling_algorithm, "rr") == 0 && running_time > quantum) {
            running_time = quantum;
        }
       
        current_time += running_time;
        current_process->remaining_time -= running_time;
        current_process->time_stamp = current_time;

        if (current_process->remaining_time == 0) {
            current_process->time_finished = current_time;
            if (strcmp(memory_allocation, "u") != 0) {
                deallocate(current_process, 0);
                deallocate_print();
            }
            printf("%lld, FINISHED, id=%lld, proc-remaining=%lld\n",\
             current_time, current_process->process_id, process_remaining());
        }
    }
}

void set_argument(char type[], char arg[]) {
    // used for set arguments
    if (strcmp(type, "-f") == 0) {
        strcpy(filename, arg);
        return;
    }
    if (strcmp(type, "-a") == 0) {
        strcpy(scheduling_algorithm, arg);
        return;
    }
    if (strcmp(type, "-m") == 0) {
        strcpy(memory_allocation, arg);
        return;
    }
    if (strcmp(type, "-s") == 0) {
        memory_size = atoi(arg) / 4;
        return;
    }
    if (strcmp(type, "-q") == 0) {
        quantum = atoi(arg);
        return;
    }
}

void performance_statistics() {
    // measure overall performance
    long long makespan = current_time;
    long long minutes = (makespan + 59) / 60;
    long long *throughputs = malloc(sizeof(long long) * minutes);
    memset(throughputs, 0, sizeof(long long) * minutes);
    long long total_turnaround = 0;
    double total_overhead = 0, max_overhead = 0;
    long long process_number = 0;
    for (struct process *tail = head; tail != NULL; tail = tail->next) {
        throughputs[(tail->time_finished - 1) / 60]++;
        long long turnaround = tail->time_finished - tail->time_arrived;
        total_turnaround += turnaround;
        double overhead = 1.0 * turnaround / tail->job_time;
        total_overhead += overhead;
        max_overhead = MAX(overhead, max_overhead);
        process_number++;
    }

    long long max_throughput = 0, min_throughput = INT_MAX, total_throughput = 0;
    for (int i = 0; i < minutes; i++) {
        total_throughput += throughputs[i];
        max_throughput = MAX(throughputs[i], max_throughput);
        min_throughput = MIN(throughputs[i], min_throughput);
    }
    printf("Throughput %lld, %lld, %lld\n", (total_throughput + minutes - 1) /minutes, min_throughput, max_throughput);
    printf("Turnaround time %lld\n", (total_turnaround + process_number - 1) / process_number);
    printf("Time overhead %.2lf %.2lf\n", max_overhead, total_overhead / process_number);
    printf("Makespan %lld\n", makespan);
    free(throughputs);
}

int main(int argc, char* argv[]) {
    memset(memory, -1, sizeof(memory));
    memset(memory_stamp, -1, sizeof(memory_stamp));
    for (int i = 1; i < argc; i += 2) {
        set_argument(argv[i], argv[i+1]);
    }
    read_processes();
    schedule();
    performance_statistics();
    return 0;
}