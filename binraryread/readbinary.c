#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned char uchar;

void printbin(uchar v){
  uchar c=1<<7;
  for(int i=0; i<8;i++){
    uchar tmp = v & (c>>i);
    if(tmp==0){
      printf("0");
    }
    else{
      printf("1");
    }
  }


}
void rb(){
  FILE *pf = fopen("./test.dict","rb");
  uchar buff[1024];
  uchar pre_shift = 0;
  uchar tail = 0;
  int counter = 0;
  int len = 0;
  while(fread(buff,1,1024,pf)!=0){
    uchar *data = NULL;
    for(int head=0;head<1024;){
      uchar l_val = buff[head]<<pre_shift;
      uchar r_val=buff[head+1]>>(8-pre_shift);
      len = l_val | r_val;

      uchar num = (len - pre_shift) / 8;
      tail = len - num*8 - pre_shift;
      printf("h:%d;len:%d;pre_shift:%d;pre_trail %d;num:%d;\n",head,len,pre_shift,tail,num);


      if(pre_shift == 0){
        if(tail == 0){
          data = (uchar*)malloc(sizeof(uchar)*num);
          memcpy(data, &buff[head], num);
          for(int i=0;i<num;++i){
            printbin(data[i]);
          }
          head += num;

        }else{

          data = (uchar*)malloc(sizeof(uchar)*num+1);
          memcpy(data, &buff[head], num+1);
          for(int i=0;i<num+1;++i){
            printbin(data[i]);
          }
          head += num;
          pre_shift = tail;
        }

      }else{

        if(tail == 0){
          data = (uchar*)malloc(sizeof(uchar)*num+1);
          memcpy(data, &buff[head-1], num+1);
          uchar rbin=data[num]>>(8-pre_shift);
          for(int i = num-1;i!=-1;--i){
            uchar tempdata = data[i]>>(8-pre_shift);
            data[i] = (data[i]<<pre_shift)| rbin;
            rbin = tempdata;
          }

          for(int i=0;i<num+1;++i){
            printbin(data[i]);
          }
          head += num;
        }else{
          uchar sumshift = pre_shift + tail;
          if(sumshift <= 8){
            data = (uchar*)malloc(sizeof(uchar)*num+1);
            memcpy(data, &buff[head-1], num+1);
            pre_shift = (8-sumshift);
          }
          else{
            data = (uchar*)malloc(sizeof(uchar)*num+2);
            memcpy(data, &buff[head-1], num+2);
            head += (num-1);
            pre_shift = sumshift -8;
          }
        }
      } 
      ++counter;
      free(data);
    } //end for
  }
}

void readbinary(){
  FILE *pf = fopen("./test.dict","rb");
  uchar buff[1024];
  uchar pre_rshift = 0;
  uchar pre_rval = 0;
  int counter =0;
  while(fread(buff,1,1024,pf)!=0){
    for(int head=0;head<1024;){
      if(counter==12){
        return;
      }
      uchar tmp = buff[head]>>pre_rshift;
      uchar tmppreval=buff[head]<<(8-pre_rshift);
      buff[head] = tmp|pre_rval;
      pre_rval = tmppreval;
      int len = buff[head];

      if(len==0){
        printf("len == 0");
        return;
      }
      // read content
      ++head;

      int shift = len%8;
      
      int num = (len-pre_rshift)/8;

      uchar *data = NULL;
      if(shift == 0){
        if(pre_rshift != 0){
          data=(uchar*)malloc(sizeof(uchar)*(num+1));
          pre_rshift=shift=8;
        }else{
          data=(uchar*)malloc(sizeof(uchar)*num);
        }
        memcpy(data,&buff[head],num);
        head +=num;
        num += 1;
      }
      else{
        if(pre_rshift != 0){
          if((shift + pre_rshift)<8){
            data=(uchar*)malloc(sizeof(uchar)*(num+1));
            shift = shift+pre_rshift;
            memcpy(data,&buff[head],num+1);
            head += (num+1);
          }else if((shift + pre_rshift)>8){
            printf("error");
          }else{
            data=(uchar*)malloc(sizeof(uchar)*(num+1));
            shift = shift+pre_rshift;
            memcpy(data,&buff[head],num+1);
            head += (num+1);
            shift = 8;
          }
          num+=1;
        }else{
          data=(uchar*)malloc(sizeof(uchar)*(num+1));
          shift = shift+pre_rshift;
          memcpy(data,&buff[head],num+1);
          head += (num+1);
        }
        num +=1;
      }
      printf("length for %x:%d,head %d,shift %d,pre_rshift %d\n",counter,len,head,shift,pre_rshift);
      uchar r_shift_v=0;

      printf("code for %d: ",counter);
      for(int i=0;i<num;++i){
        r_shift_v = data[i]<<(8-shift);
        data[i] = data[i]>>shift;
        data[i] |= pre_rval;
        pre_rval = r_shift_v;
        printbin(data[i]);
      }
      pre_rshift = shift%8;
      printf("\n");
      free(data);
      counter++;
    }
  }
}


int main(){
  //readbinary();
  rb();
}
