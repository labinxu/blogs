#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
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
      v->data[v->iter++]=value;
    }
    else
    {
        int tmpsize = v->size;
        v->size *= 2;
        v->capbility=v->size+1;
        void* tmpdata=v->data;
        v->data=malloc(sizeof(void*)*v->size);
        memset(v->data, 0, sizeof(void*)*(v->size));
        memcpy(v->data, tmpdata, tmpsize+1);
        free(tmpdata);
        v->data[v->iter++]=value;
        //re-alloc
    }

}
void* vector_at(vector *v,int i){
    return v->data[i]; 
}
int vector_size(vector *v){
    return v->iter;
}
void vector_free(vector *v){
  for(size_t i=0;i<v->iter;i++){
    free(v->data[i]);
  }
  free(v->data);
}
