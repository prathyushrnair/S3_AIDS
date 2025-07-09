/*
array of struct and pointer to manage student record

given
for each student there are 3 attributes [ name roll-no total-marks  ]

functions to be added
1. insert
2. search
3. display
4.delete
5.exit
*/
#include<stdio.h>
#define max 100
typedef struct{
    int roll_no;
    float total_marks;
    char name[50];
}student;
void insert(student *pointer,int number_of_terms){
    int i=0;
    printf("Enter the details in the order of name roll no and total marks\n");
    for(i;i<number_of_terms;i++){
            scanf("%s %d %f",(pointer+i)->name,&(pointer+i)->roll_no,&(pointer+i)->total_marks);
    }
}
void search(student *pointer,int length){
    int target,flag=0,i=0;
    printf("Enter the roll no to find\n");
    scanf("%d",&target);
    for (i;i<length;i++){
            if (pointer->roll_no == target){
                flag=1;
                printf("target found..\n");
                break;
            }
    }
    if (flag == 1){
            printf("Search successful on index %d \n",i);
    }else{
        printf("Search unsuccessful\n");
    }
}

int main(){
    int length,choice=0;
    student record[max];
    student *pointer = record;
    printf("1. Insert record \n 2.Search Record\n 3.display record\n 4.delete record\n 5.Exit\n");
    while (choice !=5){

        if (choice==1){
            //insert function
            printf("How many student details to be added\n");scanf("%d",&length);
            insert(pointer,length);
        }
        else if (choice==2){
            //search function
            search(pointer,length);


        }
    }

    return 0;
}
