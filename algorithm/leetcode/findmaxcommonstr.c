#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int args,char**argv)
{

    if(args<3){
        return 1;
    }
    // ~ (127)- space(32) + 1
    char buff[94] = {0};
    for(int i = 1; i<args; i++)
    {
        char *ps = argv[i];
        size_t len = strlen(ps);
        for(size_t j=0;j<len;j++)
        {
            buff[ps[j]-32]+=1;
        }
    }
    for(int i=0;i<94;i++)
    {
      if(buff[i]!=0){
        printf("%c",i+32);
      }
    }
    printf("\n");
};
