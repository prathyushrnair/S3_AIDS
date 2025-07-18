//this program deals with a polynomial problem but with linked list
//soo 2 data struct one for data and one for head
//functions expected create, display,insert,add,multiply
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct data{
    int coeff;
    int expo;
    struct data *link;
    }node;
typedef struct{
    node *head;
    }polynomial;

polynomial create_poly(polynomial *p){
    if (p->head!=NULL){

    p->head=NULL;
    printf("Polynomial of pointer is being created\n");
    return(*p);
    }
    else{
        printf("Linked list already exists\n");
        return(*p);
    }}
// <---create function over---->
void display(polynomial *poly){
    if (poly->head==NULL){
            printf("The polynomial is empty\n");
            exit(0);
    }
    else{
        node *term=poly->head;
        while(term!=NULL){
                printf("%d ^%d",term->coeff,term->expo);
                printf(" + ");
        }
    }
}
// <---display function over---->
polynomial insert(polynomial *poly,int coeff,int expo)
{
    if (poly->head==NULL){
        printf("The polynomial is empty\n");
        exit(0);
    }
    else{
        node *term=(node*)malloc(sizeof(node));
        term->coeff=coeff;
        term->expo=expo;
        term->link=poly->head;
        poly->head=term;
        }
}

void main()
{polynomial *p=(polynomial*)malloc(sizeof(polynomial));
}











