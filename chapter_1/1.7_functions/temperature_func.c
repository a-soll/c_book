// 2020-11-06
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float conversion(int f);

int main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, conversion(fahr));
    }

    return 0;
}

float conversion(int f) {
    return (5.0 / 9.0) * (f - 32);
}
