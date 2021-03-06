// 12-19-2020
#include <stdio.h>

#define MAXLINE 1000

extern int n;
int get_line(char line[]);

// Write a program called detab that replaces tabs in the input with the proper
// number of blanks to create space to the next tab stop assume a fixed set of tab stops,
// say every n columns. Should n be a variable or symbolic parameter?
int main() {
    int len;            // current line length
    char line[MAXLINE]; // current line
    while ((len = get_line(line)) > 0) {
        printf("%s", line);
    }
}

// Gets the line from stdin
int get_line(char line[]) {
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c; // test comment
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}
