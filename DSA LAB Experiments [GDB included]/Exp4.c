#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100


char opStack[MAX];
int topOp = -1;

int valStack[MAX];
int topVal = -1;


void pushOp(char c) {
    if (topOp == MAX - 1) {
        printf("Operator stack overflow!\n");
        exit(1);
    }
    opStack[++topOp] = c;
}

char popOp() {
    if (topOp == -1) {
        printf("Operator stack underflow!\n");
        exit(1);
    }
    return opStack[topOp--];
}

char peekOp() {
    return (topOp == -1) ? '\0' : opStack[topOp];
}

if (topVal == MAX - 1) {
        printf("Value stack overflow!\n");
        exit(1);
    }
    valStack[++topVal] = val;
}

int popVal() {
    if (topVal == -1) {
        printf("Value stack underflow!\n");
        exit(1);
    }
    return valStack[topVal--];
}


int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}


int isRightAssociative(char c) {
    return (c == '^');
}


void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {

            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            continue;
        }
        else if (isalpha(infix[i])) {
            postfix[k++] = infix[i++];
            postfix[k++] = ' ';
            continue;
        }
        else if (infix[i] == '(') {
            pushOp(infix[i]);
        }
        else if (infix[i] == ')') {
            while (topOp != -1 && peekOp() != '(') {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            popOp();
        }
        else {
            while (topOp != -1 &&
                   ((precedence(peekOp()) > precedence(infix[i])) ||
                    (precedence(peekOp()) == precedence(infix[i]) && !isRightAssociative(infix[i])))) {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            pushOp(infix[i]);
        }
        i++;
    }

    while (topOp != -1) {
        postfix[k++] = popOp();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}


int evaluatePostfix(char *postfix) {
    int values[256] = {0};
    int isSet[256] = {0};
    char token[MAX];
    int i = 0;

    while (sscanf(postfix + i, "%s", token) == 1) {
        i += strlen(token) + 1;

        if (isdigit(token[0])) {
            pushVal(atoi(token));
        }
        else if (isalpha(token[0]) && strlen(token) == 1) {
            char var = token[0];
            if (!isSet[(int)var]) {
                printf("Enter the value of %c: ", var);
                scanf("%d", &values[(int)var]);
                isSet[(int)var] = 1;
            }
            pushVal(values[(int)var]);
        }
        else {
            int op1 = popVal();
            int op2 = popVal();
            switch (token[0]) {
                case '+': pushVal(op2 + op1); break;
                case '-': pushVal(op2 - op1); break;
                case '*': pushVal(op2 * op1); break;
                case '/': pushVal(op2 / op1); break;
                case '^': pushVal((int)pow(op2, op1)); break;
            }
        }
    }

    return popVal();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    int ans = evaluatePostfix(postfix);
    printf("Answer = %d\n", ans);

    return 0;
}
