#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void (*member)(size_t i);

#define FUNC(args...)\
    printf(args)

typedef struct vector{
    size_t size;
    char *data;
    size_t iter;
    size_t capbility;

} vector;

vector create_vector(size_t size){
    vector v;
    v.size = size;
    v.iter=0;
    v.data=(char*)malloc(sizeof(char)*size+1);
    memset(v.data,0,sizeof(char)*size+1);
    v.capbility=size;
    return v;
};

void push_back(vector *v,char vi){
    //
    if(v->iter+1 <= v->capbility)
    {
        v->data[v->iter++]=vi;
    }
    else
    {
        int tmpsize = v->size;
        v->size *= 2;
        v->capbility=v->size+1;
        char* tmpdata=v->data;
        v->data=(char*)malloc(sizeof(char)*v->size);
        memset(v->data, 0, sizeof(char)*(v->size));
        memcpy(v->data, tmpdata, tmpsize+1);
        free(tmpdata);
        v->data[v->iter++]=vi;
        //re-alloc
    }

}
char at(vector *v,int i){
    return v->data[i];
}
int size(vector *v){
    return v->iter;
}
void release(vector *v){
    free(v->data);
}
char* data(vector *v)
{
    return v->data;
}


int main_(){
    vector v=create_vector(1);
    push_back(&v,'a');
    printf("%c\n",at(&v,0));
    printf("%s\n",data(&v));
    printf("size %d\n",size(&v));
    return 0;
}
