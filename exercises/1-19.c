// 11-27-2020
#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int maxline);
void reverse(char from[], char to[], int len);

// Write a function reverse(s) that reverses the character string s.
// Use it to write a program that reverses its input a line at a time
int main(int argc, char const *argv[]) {
    int len;
    char line[MAXLINE];
    char rev[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, rev, len);
    }
    printf("%s", rev);
    return 0;
}

int get_line(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline && (c = getchar()) != EOF; i++) {
        line[i] = c;
    }
    return i;
}

void reverse(char from[], char to[], int len) {
    int count = 0;

    for (int i = len - 1; i >= 0; i--) {
        to[count] = from[i];
        count++;
    }
}
