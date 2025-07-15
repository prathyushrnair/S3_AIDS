#include<stdio.h>
#include<stdlib.h>
typedef struct term{
    int coefficent;
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
void insert(polynomial *p,int coefficent, int exponent){
    TERM *new_node=(TERM*)malloc(sizeof(TERM));
    new_node->coefficent=coefficent;
    new_node->exponent=exponent;
    new_node->link=NULL;
    if (p->head==NULL){
        p->head=new_node;
    }
    else{
        TERM *curr= p->head;
        TERM *prev=NULL;

        while (curr!=NULL){
                prev=curr;
                curr=curr->link;
                 if (p->head==NULL){ //can someone explain this bit i can seem to get stuck at this spot
                     new_node->link=p->head;
                     p->head=new_node;
                }
                else{
                new_node->link=curr;
                prev->link = new_node;
                }
        }
    }
}

void display(polynomial *p){
    TERM *current=p->head;
    if (p->head==NULL){
        printf("........EMPTY List......\n");
        exit(0);
    }
    printf("Here are the details\n");
    while(current!=NULL){
            printf("%d ^ %d",current->coefficent,current->exponent);
    }
    if(current->link==NULL){
        printf("+");
    }

}

void main(){
    int choices;
    printf("These are the choices\n");
    printf(" 1.Create Polynomial\n 2.Insert an polynomial with args pointer , coefficent and exponent\n");
    printf(" 3.Display Polynomials with arg as polynomial pointer");
    printf("Enter the choices from above\n");
    scanf("%d",&choices);
    if (choices==1){
            //create function choice
            create();
    }
    else if (choices==2){
            //insert function choice
            insert(*P1,2,3);
            insert(*P2,3,4);
            printf("Inserted 2 initialize inputs\n");
    }
    else if(choices==3){
        display(*P1);
    }
}

