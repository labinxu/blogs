#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

typedef unsigned int uint;
typedef int BOOL;
#define FALSE 0
#define TRUE 1;
const int END_CHAR = 4 ;
const int PWD4 = 2;
const int PWD6 = 3;
//char LEXI_CHARS[] =  {" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"}
char LEXI_CHARS[] =  {"0123456789"};
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
void printresult(char *ret){
    char *npos = ret+END_CHAR;
    for(char*b=ret; b!=npos; b++){
        printf("%d",(int)(*b));
    }
    printf("\n");
}
void allLexicographicRecur (char *str, char* data, int last, int index) {
    int i, len = strlen(str);
    for ( i=0; i<len; i++ )
    {
        data[index] = str[i];
        if (index == last){
          printf("lexi %s\n", data);
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
    int index = 0,pos = 0;
    while(index != END_CHAR){
        printf("%d ", ret[index]);
        if((int)ret[index] != 1){
            index++;
            continue;
        }
        str[pos++] = LEXI_CHARS[index];

        index++;
    }
    printf("\n");
}

void crack(int pwd_len,char *ret){
    char* lexichars = (char*)malloc(pwd_len);
    memset(lexichars, 0, pwd_len);
    lexichars[pwd_len] = '\0';
    MakeLexiChars(ret, lexichars);
    //printf("chars:%s\n",lexichars);
    allLexicographic(lexichars);
}

void combinations(int level, char* ret){
    char *npos = ret + END_CHAR;
    int sum = accumulate(ret, npos);
    if(sum == PWD4 || sum == PWD6){
        //printresult(ret);
        crack(sum, ret);
    }
    if(sum == PWD6){
        return;
    }

    if(level==END_CHAR){
        return;
    }

    for(int i=level; i<END_CHAR; ++i){
        ret[i] = 1;
        combinations(i+1, ret);
        ret[i] = 0;
    }
}
int main(int args, char** argv){

    clock_t start_t, end_t;
    double total_t = 0;
    start_t = clock();
    printf("start_t = %ld\n", start_t);
    char *result=(char*)malloc(END_CHAR);
    memset(result, 0, END_CHAR);
    result[END_CHAR] = '\0';
    for(int i=0; i< END_CHAR; ++i){
        result[i] = 1;
        combinations(i+1, result);
        result[i] = 0;
    }
    end_t = clock();
    printf("end_t = %ld\n", end_t);
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("total CPU comsume：%f\n", total_t  );
    return 0;
}
