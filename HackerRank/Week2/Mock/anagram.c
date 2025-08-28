#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int anagram(char *s) {
    int n = strlen(s);
    if (n % 2 != 0) return -1;

    int half = n / 2;
    char a[half + 1], b[half + 1];
    strncpy(a, s, half);
    a[half] = '\0';
    strncpy(b, s + half, half);
    b[half] = '\0';

    int freq_a[256] = {0}, freq_b[256] = {0};

    for (int i = 0; i < half; i++) {
        freq_a[(unsigned char)a[i]]++;
        freq_b[(unsigned char)b[i]]++;
    }

    int total = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_a[i] > 0 && freq_b[i] > 0) {
            total += freq_a[i] < freq_b[i] ? freq_a[i] : freq_b[i];
        }
    }

    return half - total;
}

int main() {
    int q;
    scanf("%d\n", &q);

    while (q--) {
        char s[10001]; // adjust size as needed
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; // remove newline

        int result = anagram(s);
        printf("%d\n", result);
    }

    return 0;
}
