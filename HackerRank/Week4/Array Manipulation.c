#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000010

long long arr[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n + 1; ++i) arr[i] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long k;
        scanf("%d %d %lld", &a, &b, &k);
        arr[a] += k;
        arr[b+1] -= k;
    }
    long long max_val = 0;
    long long curr = 0;
    for (int i = 1; i <= n; ++i) {
        curr += arr[i];
        if (curr > max_val) max_val = curr;
    }

    printf("%lld\n", max_val);
    return 0;
}