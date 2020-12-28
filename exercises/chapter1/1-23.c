// 12-25-2020
#include <stdio.h>

#define MAXLINE 1000
#define true 1
#define false 0

int get_line(char in[]);
int comment_check(char a, char b);
void remove_comments(char in[], char out[], int len);
int inline_check(char a, char b);
int block_start(char a, char b);
int block_end(char a, char b);

int block = false;
int quote = false;

// Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly.
// C comments do not nest.
int main() {
    int len;
    char in[MAXLINE];
    char out[MAXLINE];

    while ((len = get_line(in)) > 0) {
        remove_comments(in, out, len);
        printf("%s", out);
    }
    return 0;
}

int get_line(char in[]) {
    int i, c;

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

void remove_comments(char in[], char out[], int len) {
    int i;
    int comment = false;

    for (i = 0; i < len; i++) {
        comment = comment_check(in[i], in[i + 1]);
        if (in[i] == '"') {
            if (quote) {
                quote = false;
            } else {
                quote = true;
            }
        }
        if (!quote && !block) { // check for start of block comment
            block = block_start(in[i], in[i + 1]);
        }
        if (!quote && block) { // check for end of block comment
            int i = 0;
            while (in[i++] && block) {
                block = block_end(in[i], in[i + 1]);
            }
            in[i] = '\0';
        }
        if ((comment || block) && !quote) {
            out[i] = '\0';
            break;
        } else {
            out[i] = in[i];
        }
        out[i + 1] = '\0';
    }
}

int comment_check(char a, char b) {
    if (a == '/' && b == '/') {
        return true;
    }
    return false;
}

int block_start(char a, char b) {
    if (a == '/' && b == '*') {
        return true;
    }
    return false;
}

int block_end(char a, char b) {
    if (a == '*' && b == '/') {
        return false;
    }
    return true;
}
