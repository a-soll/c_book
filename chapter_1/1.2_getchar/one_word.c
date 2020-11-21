// 2020-10-26
#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
    int c, current_value, not_word, last_value, state;

    current_value = not_word = last_value = 0;
    state = IN;
    while((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == ' '){
            state = OUT;
            ++not_word;
        }
        if (state == IN){
            current_value = not_word;
            if (not_word > last_value && last_value > 0) {
                printf("\n");
            }
            printf("%c", c);
            last_value = current_value;
        } else if (state == OUT) {
            state = IN;
        }
    }

    return 0;
}
