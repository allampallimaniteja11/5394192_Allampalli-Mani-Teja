#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_cols, int arr[][arr_cols]) {
    int primary_diag_sum = 0;
    int secondary_diag_sum = 0;
    
    for (int i = 0; i < arr_rows; i++) {
        primary_diag_sum += arr[i][i];
        secondary_diag_sum += arr[i][arr_cols - 1 - i];
    }
    
    return abs(primary_diag_sum - secondary_diag_sum);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int result = diagonalDifference(n, n, arr);
    printf("%d\n", result);
    
    return 0;
}
