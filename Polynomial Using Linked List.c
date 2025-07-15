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
    if (current == NULL){
    printf("Empty polynomial.\n");
    return;
    }
    printf("Here are the details\n");
    while(current!=NULL){
            printf("%d ^ %d",current->coefficient,current->exponent);

    if(current->link==NULL){
        printf("+");
    }
    current=current->link;
    }
    printf("\n");

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
                int n,coefficient,exponent;
                //insert function choice
                printf("Enter the number of terms to be added\n");
                scanf("%d",&n);
                printf("Enter the coefficient and Exponent of the terms\n");
                for(int i=0;i<n;i++){
                    scanf("%d %d",&coefficient,&exponent);
                    insert(&p1,coefficient,exponent);

                }printf("Record Entered...\n");
        }
        else if(choices==3){
            display(&p1);
        }
}
}

