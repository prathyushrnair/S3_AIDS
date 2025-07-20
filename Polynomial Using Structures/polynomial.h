#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#define MAX 100
//data definitions and function definitions
typedef struct term
{
    int coeff;
    int expo;
}TERM;
typedef struct
{
    int number_of_terms;
    TERM arr[MAX];
}polynomial;
void insert_poly(polynomial *p,int coeff,int expo);
void display(polynomial *poly);
polynomial add(polynomial poly1,polynomial *poly2);
polynomial *prdt(polynomial *poly1,polynomial *poly2);

#endif // POLYNOMIAL_H_INCLUDED
