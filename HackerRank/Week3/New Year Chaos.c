#include <stdio.h>

void minimumBribes(int q_count, int* q) {
    int bribes = 0;

    
    for (int i = 0; i < q_count; i++) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
    }

    
    for (int i = 0; i < q_count; i++) {
        int start = (q[i] - 2 > 0) ? q[i] - 2 : 0;
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }

    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        minimumBribes(n, q);
    }

    return 0;
}