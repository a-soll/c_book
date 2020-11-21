#include <stdio.h>

int main(){
    int arr[10];
    int length, c, i;

    length = 0;
    for (i = 0; i < 10; i++) {
        arr[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z'){
            ++length;
        }
        else if (c >= '0' && c <= '9' || c == '\t' || c == '\n' || c == ' '){
            if (length > 0){
                ++arr[length];
            }
            length = 0;
        }
    }

    for (i = 0; i < 10; i++){
        if (arr[i] > 0) {
            printf("%d ", i);
            for (int j = 0; j < arr[i]; j++){
                printf("|");
            }
            printf("\n");
        }
    }

    return 0;
}

