#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num int 
#define str char *
#define strs char *    *

// check arg
#define argc(b,a)                               \
  while (b<3)                                   \
    return 1;                                   \
  ;

// check 2ch
#define ch2c(a)                                 \
  slen(a)                                       \
    if (len < 10)                               \
      {printf("%s length less than 10\n",a);   \
        return len & 1;}

// len
#define slen(s)                                 \
  len = 0;                                      \
  while ( *(s+len++) && len<(1<<8) )            \
    ;

// allocate space
#define smelloc(a, b, c)                        \
  malloc( *(*a + b) + *(*a + c) );

// copy memory
#define place(p, a, b, c, bs, cs)               \
  memcpy(p, (*(a+b)), *(*a + bs));                 \
  memcpy(p + *(*a + bs), (*(a+c)), *(*a + cs));    \
  *(char*)(p+*(*a+bs)+*(*a+cs)) = '\0';            \
  ;

// concatenate two strings
int main(num len, char** a) {

  /* char c =0; */
  /* c=128; */
  /* printf("%d",(int)c); */
  /* return 0; */
  argc(len, a);
  ch2c((*a))
    slen((*(a+1)))
    *(*a + 0) = len-1;
  printf("a+1 %s, len %d\n",*(a+1), len);
  slen((*(a+2)))
    *(*a + 1) = len-1;
  printf("a+2 %s, len %d\n",*(a+2), len);

  void *p = (char*)smelloc(a, 0, 1);
  place(p, a, 1, 2, 0, 1);
  *a = (char*)p;
  printf("%s\n", *a);
  free(*a);

  return 0;
}
