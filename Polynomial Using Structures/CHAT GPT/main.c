#include <stdio.h>
#include "Data_Definition.h"

int main() {
    Polynomial poly1, poly2;

    printf("Enter first polynomial:\n");
    inputPolynomial(&poly1);

    printf("\nEnter second polynomial:\n");
    inputPolynomial(&poly2);

    printf("\nPolynomial 1: ");
    displayPolynomial(&poly1);

    printf("Polynomial 2: ");
    displayPolynomial(&poly2);

    Polynomial sum = addPolynomials(&poly1, &poly2);
    printf("\nAddition Result: ");
    displayPolynomial(&sum);

    Polynomial product = multiplyPolynomials(&poly1, &poly2);
    printf("Multiplication Result: ");
    displayPolynomial(&product);

    return 0;
}
