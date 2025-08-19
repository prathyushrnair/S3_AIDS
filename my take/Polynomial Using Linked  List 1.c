#include<stdio.h>
#include<stdlib.h>
typedef struct term{
    int coeff;
    int exp;
    struct term *link;
}TERM;
typedef struct{
    TERM *head;
}polynomial;
polynomial *create_poly(){
    polynomial *p=(polynomial*)malloc(sizeof(polynomial));
    p->head=NULL;
    return p;
}
void insert_poly(polynomial *p,int coeff,int exp){
    TERM *new_node=(TERM*)malloc(sizeof(TERM));
    new_node->coeff=coeff;
    new_node->exp=exp;
    new_node->link=NULL;
    if(p->head==NULL)
    {
        p->head=new_node;
    }
    else
    {   TERM *temp=p->head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new_node;
    }

    }
void display_poly(polynomial *p){
    if(p->head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        TERM *temp=p->head;
        while(temp!=NULL)
        {
            printf("%dx^%d",temp->coeff,temp->exp);
            if(temp->link!=NULL)
            {
                printf("+");
            }
            temp=temp->link;
        }
    }
}
polynomial *add_poly(polynomial *p1,polynomial *p2){
    TERM *t1,*t2;
    polynomial *result=create_poly();
    t1=p1->head;
    t2=p2->head;

    while(t1!=NULL && t2!=NULL)
    {
        if(t1->exp > t2->exp)
        {
            insert_poly(result,t1->coeff,t1->exp);
            t1=t1->link;
        }
        else if(t1->exp < t2->exp)
        {
            insert_poly(result,t2->coeff,t2->exp);
            t2=t2->link;
        }
        else
        {
            int sum=t1->coeff + t2->coeff;
            if(sum!=0)
            {
                insert_poly(result,sum,t1->exp);
            }
            t1=t1->link;
            t2=t2->link;
        }
    }
    while(t1!=NULL)
    {
        insert_poly(result,t1->coeff,t1->exp);
        t1=t1->link;
    }
    while(t2!=NULL)
    {
        insert_poly(result,t2->coeff,t2->exp);
        t2=t2->link;
    }
    return result;

}

int main()
{
    int exp,co,n,i;
    printf("enter the number of terms");
    scanf("%d",&n);
    printf("creating polynomial A\n");
    polynomial *a=create_poly();
    for(i=0;i<n;i++)
    {
        printf("enter the coefficient of term %d\n",i+1);
        scanf("%d",&co);
        printf("enter the exponent of term %d\n",i+1);
        scanf("%d",&exp);
        insert_poly(a,co,exp);
    }
    printf("creating polynomial b!\n");
    polynomial *b=create_poly();
    for(i=0;i<n;i++)
    {
        printf("enter the coefficient of term %d\n",i+1);
        scanf("%d",&co);
        printf("enter the exponent of term %d\n",i+1);
        scanf("%d",&exp);
        insert_poly(b,co,exp);
    }
    printf("\n polynomial A \n");
    display_poly(a);
    printf("\n polynomial b \n");
    display_poly(b);
    polynomial *sum=add_poly(a,b);
    printf("\n sum \n");
    display_poly(sum);

}
