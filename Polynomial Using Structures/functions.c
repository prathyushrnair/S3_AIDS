#include <stdio.h>
#include "Data_Definition.h"

void inputPolynomial(Polynomial* poly) {
    printf("Enter number of terms: ");
    scanf("%d", &poly->size);

    for (int i = 0; i < poly->size; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly->terms[i].coeff, &poly->terms[i].exp);
    }
}

// Sorting for clean display and operations (descending exponent)
void displayPolynomial(const Polynomial* poly) {
    for (int i = 0; i < poly->size; i++) {
        printf("%dx^%d", poly->terms[i].coeff, poly->terms[i].exp);
        if (i < poly->size - 1)
            printf(" + ");
    }
    printf("\n");
}

// Addition of two polynomials
Polynomial addPolynomials(const Polynomial* p1, const Polynomial* p2) {
    Polynomial result = {.size = 0};
    int i = 0, j = 0;

    while (i < p1->size && j < p2->size) {
        if (p1->terms[i].exp > p2->terms[j].exp)
            result.terms[result.size++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            result.terms[result.size++] = p2->terms[j++];
        else {
            int sumCoeff = p1->terms[i].coeff + p2->terms[j].coeff;
            if (sumCoeff != 0) {
                result.terms[result.size].coeff = sumCoeff;
                result.terms[result.size].exp = p1->terms[i].exp;
                result.size++;
            }
            i++; j++;
        }
    }

    while (i < p1->size)
        result.terms[result.size++] = p1->terms[i++];
    while (j < p2->size)
        result.terms[result.size++] = p2->terms[j++];

    return result;
}

// Multiplication of two polynomials
Polynomial multiplyPolynomials(const Polynomial* p1, const Polynomial* p2) {
    Polynomial result = {.size = 0};

    for (int i = 0; i < p1->size; i++) {
        for (int j = 0; j < p2->size; j++) {
            int coeff = p1->terms[i].coeff * p2->terms[j].coeff;
            int exp = p1->terms[i].exp + p2->terms[j].exp;

            // Check if exponent already exists
            int found = 0;
            for (int k = 0; k < result.size; k++) {
                if (result.terms[k].exp == exp) {
                    result.terms[k].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                result.terms[result.size].coeff = coeff;
                result.terms[result.size].exp = exp;
                result.size++;
            }
        }
    }

    return result;
}
