#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
vector make_vector(size_t typesize, size_t size){
  vector v;
  v.typesize=typesize;
  v.size=size;
  v.iter=0;
  v.data=malloc(typesize*size);
  memset(v.data,0,typesize*size);
  v.capbility=size;
  return v;
}
vector create_vector(size_t size){
    vector v;
    v.size = size;
    v.iter=0;
    v.data=malloc(sizeof(void*)*size);
    memset(v.data,0,sizeof(void*)*size);
    v.capbility=size;
    return v;
};

void vector_push_back(vector *v,void *value){
    //
    if(v->iter+1 <= v->capbility)
    {
      memcpy(v->data+((v->typesize)*(v->iter)), value, v->typesize);
    }
    else
    {
        int tmpsize = v->size;
        v->size *= 2;
        v->capbility=v->size;
        void* tmpdata=v->data;
        v->data=malloc(v->typesize*v->size);
        memset(v->data, 0, v->typesize*(v->size));
        memcpy(v->data, tmpdata, tmpsize*v->typesize);
        free(tmpdata);
        memcpy(v->data+((v->typesize)*(v->iter)), value, v->typesize);
    }
    v->iter++;
}
void* vector_remove(vector *v,size_t i){
  size_t size = vector_size(v);
  if(i>=size)
    return NULL;

  for(size_t j=i; j<size; ++j)
    {
      void *rm = v->data+(v->typesize)*j;
      void *src = v->data+((v->typesize)*(j+1));
      memcpy(rm, src, v->typesize);
    }
  v->iter--;
  void *ret = v->data + (v->typesize * i);
  return ret;
}

void* vector_find(vector *v, void *value, compare comp){
  size_t size = v->iter;
  for(size_t i=0; i<size; ++i){
    void *iv = vector_at(v, i);
    if(comp(iv,value)==0){
      return v->data+(v->typesize*i);
    }
  }
  return NULL;
}
void* vector_at(vector *v,int i){
  return v->data+(v->typesize*i); 
}
int vector_size(vector *v){
    return v->iter;
}
void vector_free(vector *v){
  free(v->data);
}
