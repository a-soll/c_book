// 2020-11-21
#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int maxline);
void trim_line(char line[], int len);
int white_check(char c);

// Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
int main(int argc, char const *argv[]) {
    char input[MAXLINE];
    char line[MAXLINE];
    int len;

    while ((len = get_line(input, MAXLINE)) > 0) {
        trim_line(input, len);
        printf("%s\n", input);
    }
    return 0;
}

void trim_line(char line[], int len) {
    int n = 0;                       // position of char
    for (int i = 0; i <= len; i++) { // get index of last char
        if (line[i] != '-' && line[i] != '\n' && line[i] != '\0') {
            n = i;
        }
    }
    line[n + 1] = '\0';
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if (c == ' ') {
            s[i] = '-';
        } else {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = '\0';
        i++;
    }

    return i;
}

int white_check(char s) {
    const int len = 3;
    char white[len] = {' ', '\n', '\t'};
    for (int i = 0; i < len; i++) {
        if (s == white[i]) {
            return 1;
        }
    }
    return 0;
}
