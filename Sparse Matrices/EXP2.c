// Transpose of a sparse matrix and sum of two sparse matrices.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct trm{
    int coeff;
    int expo;
    int val;
}term;
void main(){
    term arr1[MAX],arr2[MAX],arr3[MAX]; //arr3 is for addition
    int na,nb,i=0,j=0,k=0;
    printf("Enter the Number of non zero \n");
    scanf("%d",&na);
    for(i;i<na;i++){
        printf("Enter the Coeff And Expo for %d\n",i+1);
        scanf("%d %d",&arr1[i].coeff,&arr1[i].expo);
    }
    for(j;j<nb;j++){
        printf("Enter the Coeff And Expo for %d\n",j+1);
        scanf("%d %d",&arr2[j].coeff,&arr2[j].expo);
    }
    //inserted into 2 polys
    while(i<na && j<nb){
        continue;
    }
}
//https://chatgpt.com/s/t_6883bad1f7a88191abce60dc9c9ec9d2 <--refer this for "reference"
