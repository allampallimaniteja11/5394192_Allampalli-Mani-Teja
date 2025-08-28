#include <stdio.h>

void sortArray(int n, int ar[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ar[j] > ar[j+1]) {
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

int sockMerchant(int n, int ar[]) {
    sortArray(n, ar);
    int pairs = 0;
    int i = 0;
    while (i < n - 1) {
        if (ar[i] == ar[i+1]) {
            pairs++;
            i += 2;
        } else {
            i++;
        }
    }
    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    printf("%d", sockMerchant(n, ar));
    return 0;
}
