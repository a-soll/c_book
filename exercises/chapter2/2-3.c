// 12-27-2020
#include <stdio.h>

int htoi(char s[]) {
    int i = 0;
    int n;

    n = 0;

    if ((s[0] == '0' && s[1] == ('x')) || (s[0] == 'x' && s[1] == '0')) { // accounts for optional 0x or x0 prefix
        i = 2;
    }
    while (s[i]) {
        int digit;
        if (s[i] >= '0' && s[i] <= '9') {
            digit = (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            digit = (s[i] - 'A' + 10);
        } else {
            break;
        }
        n = 16 * n + digit;
        i++;
    }
    return n;
}

// Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or x0)
// into its equivalent integer value. The allowable digits are 0-9, a-f, and A-F.
int main() {
    char s[10] = "x0A1FC23";
    int n = htoi(s);

    printf("%d", n);
    return 0;
}
