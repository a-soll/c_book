// 12-25-2020
#include <stdio.h>

#define MAXLINE 1000

int get_line(char in[]);
void remove_comments(char in[], int len);

int main() {
    int len;
    char in[MAXLINE];

    len = get_line(in);
    printf("%d\n", len);
    remove_comments(in, len);
    printf("%s", in);

    return 0;
}

int get_line(char in[]) {
    int i, c;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; i++) {
        in[i] = c;
    }
    if (c == EOF) {
        in[i] = '\0';
    }

    return i;
}

void remove_comments(char in[], int len) {
    int i;
    int spot = 0;    // used to overwrite commented lines with non-comments
    int in_line = 0; // 1 if comment is inline

    for (i = 0; i < len - 1; i++) {
        if (in[i] == '/' && in[i + 1] == '/') {
            while (in[i] != '\n') {
                i++;
            }
            if (in_line == 1) { // if inline comment, preserve newline
                i--;
            }
        } else {
            in_line = 1;
            in[spot] = in[i];
            spot++;
        }
        if (in[i] == '\n') { // reset inline each line
            in_line = 0;
        }
    }
    in[spot] = '\0';
}
