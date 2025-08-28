#include <stdio.h>
#include <stdlib.h>

int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int getLCM(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int gcd = getGCD(a, b);
    return abs(a * b) / gcd;
}

int getTotalX(int *a, int n, int *b, int m) {
    int lcm = a[0];
    for (int i = 1; i < n; i++) {
        lcm = getLCM(lcm, a[i]);
    }

    int gcd = b[0];
    for (int i = 1; i < m; i++) {
        gcd = getGCD(gcd, b[i]);
    }

    int count = 0;
    int multiple = lcm;
    while (multiple <= gcd) {
        if (gcd % multiple == 0) count++;
        multiple += lcm;
    }

    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n], b[m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int total = getTotalX(a, n, b, m);
    printf("%d\n", total);

    return 0;
}
