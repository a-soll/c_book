// 01-04-2020
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double atof(char s[]) {
    double val, power;
    int i, sign;
    double num;

    for (i = 0; isspace(s[i]); i++)
        ;                          // skip leading whitespaces
    sign = (s[i] == '-') ? -1 : 1; // if s[i] == '-', sign = -1. else sign = 1
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) { // val = value to left of decimal
        val = 10.0 * val + (s[i] - '0');  // val * 10 to shift left
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) { // right of decimal
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    num = sign * val / power;
    power = 1.0;
    if (s[i] == 'e' || s[i] == 'E') { // scientific notation
        sign = '+';
        i++;
        if (s[i] == '-') {
            sign = '-';
            i++;
        }
        for (val = 0.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
        }
        for (i = 0; i < val; i++) {
            power *= 10;
        }
        if (sign == '-') {
            num /= power;
        } else {
            num *= power;
        }
    }
    return num;
}

int main() {
    char n[10] = "123.45e-6";
    double m;

    m = atof(n);
    printf("%.10f", m);
}
