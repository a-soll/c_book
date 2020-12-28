// 12-26-2020
#include <stdio.h>

#define MAXLINE 1000
#define true 1
#define false 0

int check_missing(char in[], int param, int len) {
    int opening = false; // opening quote
    int closing = false; // closing quote
    int i;
    int count;

    for (i = 0; i < len; i++) {
        if (in[i] == param) {
            if (!opening) {
                opening = true;
            } else if (opening && !closing) {
                closing = true;
            } else {
                closing = false;
            }
        }
    }
    if (!(opening == closing)) {
        return true;
    }
    return false;
}

int get_line(char in[]) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        in[i] = c;
    }
    if (c == '\n') {
        in[i] = c;
        i++;
    }
    in[i] = '\0';
    return i;
}

// Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
// brackets, and braces. Don't forget about quotes, both single and double, escape sequences, and
// comments.
int main() {
    char in[MAXLINE];
    char out[MAXLINE];
    int len;
    int single = 0;
    int dub = 0;
    int count = 0;

    while ((len = get_line(in)) > 0) {
        single += check_missing(in, '\'', len);
        dub += check_missing(in, '\"', len);
        count++;
    }
    enum boolean {TRUE, FALSE};
    printf("%d\n", single);
    printf("%d\n", dub);
    return 0;
}
