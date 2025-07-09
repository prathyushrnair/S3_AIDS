/*
array of struct and pointer to manage student record

given
for each student there are 3 attributes [ name roll-no total-marks  ]
*/
#include<stdio.h>
#define max 100
typedef struct{
    int roll_no;
    float total_marks;
    char name[50];
}student;
void main(){
    int i=0,length;
    student record[max];
    student *pointer = record;
    printf("Enter the number of details to be added \n");scanf("%d",&length);
    printf("Enter the details in the order of name roll no and total marks\n");
    for(i;i<length;i++){
            scanf("%s %d %f",(pointer+i)->name,&(pointer+i)->roll_no,&(pointer+i)->total_marks);
    }
}

