// Transpose of a sparse matrix and sum of two sparse matrices.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct trm{
    int row;
    int column;
    int val;
}term;
//data definition  ⬆️
void display(term mat[],int terms){
    printf("Enter the details in this format\n");
    printf("ROW \tCOLUMN \tVALUE \t\n");
    for(int i=0;i<terms;i++){
        printf("%d\t%d\t%d\n",mat[i].row,mat[i].column,mat[i].val);
    }
}
void insert(term mat[],int *row,int *col,int *terms){
    printf("Enter rows , columns , non zero terms\n");
    scanf("%d%d%d",row,col,terms);
    printf("Enter element in this format ROW COLUMN VALUE\n");
    for(int i=0;i<*terms;i++){
        scanf("%d %d %d",&mat[i].row,&mat[i].column,&mat[i].val);
    }
}

void transpose(term arr1[],term arr2[],int rows,int cols,int terms){
    int k=0;
    for(int i=0;i<cols;i++){
        for(int j=0;j<terms;j++){
            if(arr1[j].column==i){
                arr2[k].row=arr1[j].column;
                arr2[k].column=arr2[j].row;
                arr2[k].val=arr1[j].val;
                k++;
            }
        }
    }

}

void add(term arr1[],term arr2[],term arr3[],int *terms1,int *terms2,int *terms3){
    int i=0,j=0,k=0;
    while(i<*terms1 && j<terms2){
        if(arr1[i].row<arr2[j].row || (arr1[i].row=arr2[j].row && arr1[i].column<arr2[j].column)){
            arr3[k++]=arr2[j++];
        }
        else if(arr1[i].row>arr2[j].row ||(arr1[i].row==arr2[j].row && arr1[i].column>arr2[j].column)){
            arr3[k++]=arr2[j++];
        }
        else{
            arr3[k]=arr1[i];
            arr3[k++].val=arr1[i++].val+arr2[j++].val;
        }
    }
    while(i<terms1){
        arr3[k++]=arr1[i++];
    }
    while(j<terms2){
        arr3[k++]=arr2[j++];
    }
    *terms3=k;
}

int main(){
 term a[MAX],b[MAX],c[MAX],result[MAX];
 int rows1,rows2;
 int cols1,cols2;
 int terms1,terms2,terms3=0;
 printf("First Matrix:\n");
 insert(a,&rows1,&cols1,&terms1);
 printf("Second Matrix:\n");
 insert(b,&rows2,&cols2,&terms2);
 transpose(a,result,rows1,cols1,terms2);
 display(result,terms1);
 if(rows1==rows2 && cols1==cols2){
    add(a,b,c,&terms1,&terms2,&terms3);
    printf("\nSum of Matrices:\n");
    display(c,terms3);
 }
 else{
    printf("\nCannot Add-Different DIMENSIONS\n");
 }
 return 0;
 }


