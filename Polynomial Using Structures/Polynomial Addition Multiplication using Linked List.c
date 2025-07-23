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

polynomial *create_poly(){ //evide pointer ann return cheyunne
    polynomial *p=(polynomial*)malloc(sizeof(polynomial));
    if (p==NULL){
            printf("Pointer is null \n Memory allocation failed...\n");
            exit(1);
    }
    p->head=NULL;
    return(p);
}
// <---create function over---->
void display(polynomial *poly){
    if (poly->head==NULL){
            return;
    }
    else{
        node *term=poly->head;
        while(term!=NULL){
                printf("%d ^%d",term->coeff,term->expo);
                term=term->link;
                if (term!=NULL)
                {
                    printf(" + ");
                }
        }printf("\n");
    }
}
// <---display function over---->
void insert(polynomial *poly,int coeff,int expo)
{
    node *term=(node*)malloc(sizeof(node));
    term->coeff=coeff;
    term->expo=expo;
    term->link=NULL;
    if (poly->head==NULL){
        //inserting to a empty linked list
        printf("The polynomial is empty\n");
        poly->head=term;
    }
    else{
        term->link=poly->head;
        poly->head=term;
        }

}
//<--insert  function implemented-->
polynomial *add(polynomial *poly1,polynomial *poly2)
{
    //to add 2 poly we need a result and add same expo terms
    polynomial *result=create_poly();
    node *p1=poly1->head;
    node *p2=poly2->head;
    while(p1!=NULL && p2!=NULL){
        //this loops runs until the end of eighter poly's
        if (p1->expo==p2->expo){
        //case 1: equal exponents
        int sum;
        sum=p1->coeff+p2->coeff;
        insert(result,sum,p1->expo);
        //summation is inserted to result polynomial
        p1=p1->link;
        p2=p2->link;//traversing the entire linked list
        }
        else if(p1->expo>p2->expo){
            //case 2 : p1 expo is greater than p2 expo eg x^3 and x^2
            insert(result,p1->coeff,p1->expo);
            p1=p1->link;
        }
        else{
            //last case:p2 expo greater than p1 expo eg x^2 and x^3
            insert(result,p2->coeff,p2->expo);
            p2=p2->link;
        }

    }
    while(p1!=NULL)
        {
            insert(result,p1->coeff,p1->expo);
            p1=p1->link;
        }
    while(p2!=NULL)
        {
            insert(result,p2->coeff,p2->expo);
            p2=p2->link;
        }
    //to display the results we call display function as well
    return result;
}
//add function implemented
int main()
{
    polynomial *p1=create_poly();
    polynomial *p2=create_poly();
    //initialised 2 polynomials
    while(1){
    int choices;
    printf("1.Insert Polynomial\n 2.Display Polynomial\n 3.Add Polynomials\n 4.Break \n");
    printf("Enter the choices\n");
    scanf("%d",&choices);
    if (choices==1){
        int n=0,coeff,expo;
        printf("Enter the number of terms for poly1\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("Enter the Coefficient for %d\n",i+1);
            scanf("%d",&coeff);
            printf("Enter the Exponent for %d\n",i+1);
            scanf("%d",&expo);
            insert(p1,coeff,expo);
        }//inserted elements for p1

        int m=0,coeff1,expo1;
        printf("Enter the number of terms for poly2\n");
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            printf("Enter the Coefficient for %d\n",i+1);
            scanf("%d",&coeff1);
            printf("Enter the Exponent for %d\n",i+1);
            scanf("%d",&expo1);
            insert(p2,coeff1,expo1);
        }//inserted elements for p2
    }
    else if(choices==2)
    {
        int choice;
        //confusion about how to tackle whether how to ask whether p1 or p2
        printf("Which polynomial want to display(1/2)\n");
        scanf("%d",&choice);
        if (choice==1){
            display(p1);
        }
        else{
            display(p2);
        }

    }
    else if(choices==3)
    {
        polynomial *result;
        //option selected for addition
        result=add(p1,p2);
        display(result);
    }
    else{
        break;
    }
    }
    return(0);
}

