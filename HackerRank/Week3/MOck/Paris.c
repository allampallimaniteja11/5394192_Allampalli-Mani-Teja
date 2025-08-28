#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Binary search: returns 1 if key is in arr[0..n-1]
int binarySearch(int *arr, int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return 1;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int pairs(int k, int *arr, int n) {
    int count = 0;
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, n, arr[i] + k)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = pairs(k, arr, n);
    printf("%d\n", result);

    return 0;
}
