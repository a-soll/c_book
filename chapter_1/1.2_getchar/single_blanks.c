// 2020-10-25
#include <stdio.h>

/* count lines in input */

#define BLANK 0
#define CHAR 1

int main(){
    int c, count, state;

    count = 0;
    state = CHAR;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ') {
            if (state == CHAR) {
                printf("%c", c);
            }
            state = BLANK;
        }
        else{
            state = CHAR;
            printf("%c", c);
        }
    }

    return 0;
}
