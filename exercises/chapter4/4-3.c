// 01-16-2020
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0' // signal number was found

char inp[MAXOP] = "-5.7735 3 / 7 * 5 -"; // calculator input
int ind = 0;                        // input index
double val[MAXOP];                  // current stack
int sp;                             // stack pointer
char buf[MAXOP];                    // bufer
int bufp = 0;

int getch() { // get char from inp[] if buffer empty
    return (bufp > 0) ? buf[--bufp] : inp[ind++];
}

void ungetch(int c) {
    buf[bufp++] = c;
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void push(double f) {
    if (sp < MAXOP) {
        val[sp++] = f;
    } else {
        printf("stack full. can't push %g\n", f);
    }
}

int getop(char s[]) {
    int c;
    int j = 0;

    while ((s[0] = c = getch()) == ' ')
        ;
    s[1] = '\0';
    if (!isdigit(c) && !isdigit(inp[ind])) { // return operation
        return c;
    }
    if (!isdigit(c)) {
        if (isdigit(c = getch())) {
            s[++j] = c;
        }
    }
    if (isdigit(c) || c == '.') {
        while (isdigit(s[++j] = c = getch()) || c == '.') // collect '.' as part of double
            ;
    }
    s[j] = '\0';
    if (c != EOF) {
        ungetch(c); // add c to buffer
    }
    return NUMBER;
}

// Reverse Polish calculator that accounts for negative numbers
int main() {
    char s[MAXOP];
    int type;
    double op2;

    while ((type = getop(s)) != '\0') {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            push(pop() / op2);
            break;
        default:
            printf("error\n");
            break;
        }
    }
    printf("%f", pop());
    return 0;
}
