#ifndef vector_h
#define vector_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void (*member)(size_t i);
typedef int (*compare)(const void *, const void *);
#define FUNC(args...)\
    printf(args)

typedef struct vector{
    size_t typesize;
    size_t size;
    void* data;
    size_t iter;
    size_t capbility;

} vector;
vector make_vector(size_t typesize, size_t size);
void vector_push_back(vector *v, void*value);
void* vector_at(vector *v,int i);
int vector_size(vector *v);
void vector_free(vector *v);
char* vector_data(vector *v);
void* vector_find(vector *v, void *value, compare comp);
void *vector_remove(vector *v,size_t i);
#endif
