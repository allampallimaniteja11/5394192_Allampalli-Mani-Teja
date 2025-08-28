#include <stdio.h>

void countingSort(int arr[], int n) {
    int freq[100] = {0};  // frequency array of size 100, all initialized to 0
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Print frequency array
    for (int i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);   // number of elements
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    countingSort(arr, n);
    return 0;
}
