#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

char s[MAXN];
char result[MAXN];
int changed[MAXN];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    int left = 0, right = n - 1;
    int needed = 0;
    while (left < right) {
        if (s[left] != s[right])
            needed++;
        left++; right--;
    }

    if (needed > k) {
        printf("-1\n");
        return 0;
    }
    strncpy(result, s, n + 1);
    memset(changed, 0, sizeof(int) * n);
    left = 0; right = n - 1;
    int remaining = k;
    while (left < right) {
        if (result[left] != result[right]) {
            int bigger = max(result[left], result[right]);
            result[left] = result[right] = bigger;
            changed[left] = changed[right] = 1;
            remaining--;
        }
        left++; right--;
    }

    left = 0; right = n - 1;
    while (left <= right && remaining > 0) {
        if (left == right) {
            if (result[left] != '9' && remaining > 0) {
                result[left] = '9';
                remaining--;
            }
        } else {
            if (result[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (remaining >= 1) {
                        result[left] = result[right] = '9';
                        remaining--;
                    }
                } else if (remaining >= 2) {
                    result[left] = result[right] = '9';
                    remaining -= 2;
                }
            }
        }
        left++; right--;
    }

    printf("%s\n", result);
    return 0;
}