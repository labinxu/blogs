#include <stdio.h>
#include <stdlib.h>

// 2*2
int multi_matrix(int* mat, int dim){
  /* a  b
     c  d */
  // result  a*d - b*c
  if(dim == 2)
    return mat[0] * mat[3] - mat[1]* mat[2];
  reutrn sub_dimension(mat, dim, 0);
}

int sub_dimension(int *mat, int dim,  int rm_dim){

  for(int r=0; r < dim; ++r){
    if(rm_dim == r) continue;
    int index = 0;
    for(int c=0; c < dim; ++c){
      if(rm_dim == c) continue;
      index = r*dim + c;
      //printf("r:%d c:%d, index:%d ", r, c,index);
      printf("%d ", mat[index]);
    }
    printf("\n");
  }
}

int main(){
  int m=3;
  int mat3x3[9]={
    1,1,1,
    2,2,2,
    3,3,3
  };
  for(int i=0;i<m*m;i++){
    printf("%d ", mat3x3[i]);
    if(i%m==0){
      printf("\n");
    }
  }
  reduce_dimension(mat3x3, 3, 0);
}
