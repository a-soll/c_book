// 01-03-2021
#include <stdio.h>

// Write an alternate version of squeeze(s1,s2) that deletes each character
// in s1 that matches any character in the string s2.
void squeeze(char s[], char s2[]) {
    int i, j;
    int n = 0;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s[i] == s2[j]) {
                break;
            } else if (s2[j + 1] == '\0') { // only valid chars can get to end of s2
                s[n++] = s[i];
            }
        }
    }
    s[n] = '\0';
}

int main() {
    char s[5] = "hello";
    char s2[5] = "el";

    squeeze(s, s2);
    printf("%s", s);
    return 0;
}
