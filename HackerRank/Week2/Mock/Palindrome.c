#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int a, int b) {
    while (a < b && s[a] == s[b]) {
        a++;
        b--;
    }
    return a >= b;
}

int palindromeIndex(char *s) {
    int a = 0;
    int b = strlen(s) - 1;

    while (a < b && s[a] == s[b]) {
        a++;
        b--;
    }

    if (a >= b) return -1;

    if (isPalindrome(s, a + 1, b)) return a;
    if (isPalindrome(s, a, b - 1)) return b;

    return -1;
}

int main() {
    int q;
    scanf("%d\n", &q);

    while (q--) {
        char s[100001]; // adjust size as needed
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; // remove newline

        int result = palindromeIndex(s);
        printf("%d\n", result);
    }

    return 0;
}
