#include <stdio.h>
#define MOD 1000000007
#define MAX 1001

long long ways[MAX], total[MAX], solid[MAX];


long long mod_pow(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        ways[0] = 1;
        for (int i = 1; i <= m; i++) {
            ways[i] = 0;
            for (int j = 1; j <= 4 && i - j >= 0; j++) {
                ways[i] = (ways[i] + ways[i - j]) % MOD;
            }
        }

        for (int i = 0; i <= m; i++)
            total[i] = mod_pow(ways[i], n);

        solid[0] = 0;
        for (int i = 1; i <= m; i++) {
            solid[i] = total[i];
            for (int j = 1; j < i; j++) {
                solid[i] = (solid[i] - (solid[j] * total[i - j]) % MOD + MOD) % MOD;
            }
        }

        printf("%lld\n", solid[m]);
    }
    return 0;
}