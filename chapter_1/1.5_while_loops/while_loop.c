// 2020-10-25
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%.0f\t%6.1f\n", fahr, celsius); // 3d and 6d minimum width, .0/.1 is decimal spots
        fahr = fahr + step;
    }

    return 0;
}
