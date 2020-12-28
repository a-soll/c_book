// 12-27-2020
#include <stdio.h>

int htoi(char s[]) {
    int i = 0;
    int n;

    n = 0;
    while (s[i]) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        }
        if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        }
        i++;
    }
    return n;
}

// Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or x0)
// into its equivalent integer value. The allowable digits are 0-9, a-f, and A-F.
int main() {
    char s[10] = "A1FC23";
    int n = htoi(s);

    printf("%d", n);
    return 0;
}
