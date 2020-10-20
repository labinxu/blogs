#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

typedef unsigned int uint;
typedef int BOOL;
#define FALSE 0
#define TRUE 1;
const char BASE_CHAR = 32;
const char END_CHAR = 10;
char LEXI_CHARS[] =  {" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"};
char accumulate(char* begin, char *end){
    char sum = 0;
    while(begin != end){
        sum += *begin;
        ++begin;
    }
    return sum;
}

int compare (const void * a, const void * b){ 
    return ( *(char *)a - *(char *)b ); 
}

void allLexicographicRecur (char *str, char* data, int last, int index) {
    int i, len = strlen(str);
    for ( i=0; i<len; i++ )
    {
        data[index] = str[i] ;
        if (index == last){
            printf("%s\n", data);
            return;
        }
        else{
            allLexicographicRecur (str, data, last, index+1);
        }
    }
}

void allLexicographic(char *str) 
{
    int len = strlen (str) ;
    char *data = (char *) malloc (sizeof(char) * (len + 1)) ; 
    data[len] = '\0'; 
    qsort(str, len, sizeof(char), compare); 
    allLexicographicRecur (str, data, len-1, 0); 
    free(data);
}

void MakeLexiChars(char* ret, char* str){
    int index = 0, pos = 0;
    while(index != strlen(ret)){
        if(ret[index] != 1){
            continue;
        }
        str[pos] = LEXI_CHARS[pos];
        index++;
        ++pos;
    }
}

void combinations(int l, char* ret){
    printf("%s", ret);
    do{
        ret[l-1] = 1;
        char *npos = ret + strlen(ret);
        int sum = accumulate(ret,ret+strlen(ret));
        if (sum > 6 ){
            return;
        }
        else if (sum == 6){
            //
            printf("%s", ret);
            char * str = (char*)malloc(strlen(ret)+1);
            memset(str, '\0', strlen(ret)+1);
            MakeLexiChars(ret, str);
            allLexicographic(str);
            return;
        }
        else if (sum == 4){
            return;
        }
        ret[l-1] = 0;
        if(sum > 6){
            return;
        }
        else if(sum == 4){
            return;
        }
        else if(sum == 6){
            return;
        }
        break;
    }
    while(1);

    for(int i=l; i<END_CHAR; ++i){
        ret[i] = 1;

        combinations(i+1, ret);
        ret[i] = 0;
    }
}
int main(){
    char result[END_CHAR];
    for(int i=0; i< END_CHAR; ++i){
        printf("%i\n",i);
        result[i] = 1;
        combinations(i+1,result);
        result[i] = 0;
    }

    return 0;
}
