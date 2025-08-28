#include <stdio.h>
#define MAX 100000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int h1[MAX], h2[MAX], h3[MAX];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &h1[i]);
        sum1 += h1[i];
    }
    for (int i = 0; i < n2; ++i) {
        scanf("%d", &h2[i]);
        sum2 += h2[i];
    }
    for (int i = 0; i < n3; ++i) {
        scanf("%d", &h3[i]);
        sum3 += h3[i];
    }

    int i1 = 0, i2 = 0, i3 = 0;
    while (1) {
        if (sum1 == sum2 && sum2 == sum3) {
            printf("%d\n", sum1);
            return 0;
        }
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[i3++];
        }
    }
}