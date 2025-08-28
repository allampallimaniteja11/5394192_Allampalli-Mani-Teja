#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int flippingMatrix(int n, int matrix[2* n][2* n]) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a = matrix[i][j];
            int b = matrix[i][2*n - 1 - j];
            int c = matrix[2*n - 1 - i][j];
            int d = matrix[2*n - 1 - i][2*n - 1 - j];
            sum += max(max(a, b), max(c, d));
        }
    }
    return sum;
}

int main() {
    int q;
    scanf("%d", &q);

    while(q--) {
        int n;
        scanf("%d", &n);

        int matrix[2*n][2*n];
        for(int i = 0; i < 2*n; i++) {
            for(int j = 0; j < 2*n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = flippingMatrix(n, matrix);
        printf("%d\n", result);
    }

    return 0;
}
