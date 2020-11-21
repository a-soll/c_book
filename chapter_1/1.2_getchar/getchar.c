// 2020-10-25
#include <stdio.h>

// copy input to output; 1st version

int main() {
    int c; // int/long so that it is big enough to hold anything, including EOF

    while ((c = getchar()) != EOF){
        putchar(c);
    }

    return 0;
}
