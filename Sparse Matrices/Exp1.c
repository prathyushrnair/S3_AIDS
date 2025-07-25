//this program is to find the sum of two sparse polynomials using arrays
//the input is 2 sparse matrix and we have to perform Addition
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct term{
    int coeff;
    int expo;
}trm;

int main(){
struct term arr1[MAX],arr2[MAX],arr3[MAX];
int i=0,j=0,k=0,na,nb;
printf("Please enter the number of non zero elements for Poly1\n");
scanf("%d",&na);
for(i;i<na;i++){
    printf("Enter coeff and expo for term %d of A[in ascending order pls]\n",i+1);
    scanf("%d %d",&arr1[i].coeff,&arr1[i].expo);
    }//elements are inserted
printf("Please enter the number of non zero elements for Poly2\n");
scanf("%d",&nb);
for(j;j<nb;j++){
    printf("Enter the coeff and expo for the term %d of B [in ascending order ]\n",j+1);
    scanf("%d %d",&arr2[j].coeff,&arr2[j].expo);
}
i=0;
j=0;
while(i<na && j<nb){
    if(arr1[i].expo<arr2[j].expo){
        arr3[k].expo=arr2[j].expo;
        arr3[k++].coeff=arr2[j++].coeff;
    }
    else if(arr1[i].expo >arr2[j].expo){
        arr3[k].expo=arr1[i].expo;
        arr3[k++].coeff=arr1[i].coeff;

    }
    else{
        int sum=0;
        sum=arr1[i].coeff+arr2[j].coeff;
        if (sum!=0){
        arr3[k].coeff=sum;
        arr3[k].expo=arr1[i].expo;
        k++;
        }
    i++;
    j++;
    }
}
while(i<na){
    arr3[k++]=arr1[i++];

}
while(j<nb){
    arr3[k++]=arr2[j++];
}
printf("Result=\n");
int m=0;
for(m;m<k;m++){
    printf("%dx^%d",arr3[m].coeff,arr3[m].expo);
    if(m!=k-1 && arr3[m+1].coeff>=0){
            printf(" + ");
    }
}
return 0;
}
