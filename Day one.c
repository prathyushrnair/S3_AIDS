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

int main(){
    int length,choice=0;
    student record[max];
    student *pointer = record;
    do{
    printf("1. Insert record \n 2.Search Record\n 3.display record\n 4.remove record\n 5.Exit\n");
    printf("Enter your choice\n");scanf("%d",&choice);
    if (choice==1){
            //insert function
            printf("How many student details to be added\n");scanf("%d",&length);
            insert(pointer,length);
        }
    else if (choice==2){
            //search function
            search(pointer,length);
            }

    else if (choice==3){
        //display function
        display(pointer,length);
    }
    else if (choice==4){
        //remove record function
        delete_record(pointer,&length);
        }
    }
    while (choice!=5);
    return 0;
}

void insert(student *pointer,int number_of_terms){
    //insert function
    int i=0;
    printf("Enter the details in the order of name roll no and total marks\n");
    for(i;i<number_of_terms;i++){
            printf("Enter the Name for of %d student\n",i+1);
            scanf("%s",(pointer+i)->name);
            printf("Enter the Roll number of %d student\n",i+1);
            scanf("%d",&(pointer+i)->roll_no);
            printf("Enter the Total Mark of %d student [out of 100]\n",i+1);
            scanf("%f",&(pointer+i)->total_marks);
    }
}
void search(student *pointer,int length){
    //search function
    int target,flag=0,i=0;
    printf("Enter the roll no to find\n");
    scanf("%d",&target);
    for (i;i<length;i++){
            if ((pointer+i)->roll_no == target){
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
void display(student *pointer,int length){
    //display function
    int i=0;
    printf("Records present \nName\tRoll Number\tTotal Marks\n");
    for(int i=0; i<length ; i++){
            printf("%s \t%d \t%.2f\n",(pointer+i)->name,(pointer+i)->roll_no,(pointer+i)->total_marks);
    }
    printf("-- End of Record ---\n");
}
void delete_record(student *pointer,int *length){
    // Delete function
    int target,i=0,j=0,flag=0;
    printf("Enter the Roll number to be deleted \n");
    scanf("%d",&target);
    for (i;i<*length;i++){
        if ((pointer+i)->roll_no == target){
            flag=1;
            for (j=i;j<*length-1;j++){
                    *(pointer+j)=*(pointer+j+1);
            }
            (*length)--;
            break;
    }
}

    if (flag == 1){
        printf("The element is found and deleted\n");
    }else{
        printf("The element is not found\n");
    }

}


