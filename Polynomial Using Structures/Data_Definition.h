#ifndef DATA_DEFINITION_H_INCLUDED
#define DATA_DEFINITION_H_INCLUDED
#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int size;
} Polynomial;

void inputPolynomial(Polynomial* poly);
void displayPolynomial(const Polynomial* poly);
Polynomial addPolynomials(const Polynomial* p1, const Polynomial* p2);
Polynomial multiplyPolynomials(const Polynomial* p1, const Polynomial* p2);

#endif // DATA_DEFINITION_H_INCLUDED
