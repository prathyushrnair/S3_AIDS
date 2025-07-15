#include<stdio.h>
#include<stdlib.h>
typedef struct term{
    int coefficient;
    int exponent;
    struct term *link;
    }TERM;
typedef struct{
    TERM *head;
    }polynomial;
polynomial *p;
polynomial create(){
    //entered inside create function u need a head pointing to NULL basically
    polynomial *p=(polynomial*) malloc(sizeof(polynomial));
    p->head=NULL;
    return(*p); //returning cause then its easier to manipulate
    }
void insert(polynomial *p,int coefficient, int exponent){
    TERM *new_node=(TERM*)malloc(sizeof(TERM));
    new_node->coefficient=coefficient;
    new_node->exponent=exponent;
    new_node->link=NULL;
    if (p->head==NULL){
        p->head=new_node;
    }
    else{
        TERM *curr= p->head;
        while (curr!=NULL){
                curr=curr->link;
        }
        curr->link=new_node;
    }
}

void display(polynomial *p){
    TERM *current=p->head;
    printf("Here are the details\n");
    while(current!=NULL){
            printf("%d ^ %d",current->coefficient,current->exponent);
    }
    if(current->link==NULL){
        printf("+");
    }printf("\n");

}

void main(){
    int choices;
    polynomial p1=create();
    polynomial p2=create();
    while(1){
         printf("These are the choices\n");
        printf(" 1.Create Polynomial\n 2.Insert an polynomial with args pointer , coefficient and exponent\n");
        printf(" 3.Display Polynomials with arg as polynomial pointer");
        printf("Enter the choices from above\n");
        scanf("%d",&choices);
        if (choices==1){
                printf("Polynomials are created\n");
        }
        else if (choices==2){
                //insert function choice
                insert(&p1,2,3);
                printf("Inserted 2 initialize inputs\n");
        }
        else if(choices==3){
            display(&p2);
        }
}
}

