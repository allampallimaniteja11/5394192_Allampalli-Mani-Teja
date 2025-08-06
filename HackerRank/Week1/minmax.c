#include <stdio.h>

int main() {
    long arr[5];
    long sum = 0, min, max;
    
    // Input 5 numbers
    for (int i = 0; i < 5; i++) {
        scanf("%ld", &arr[i]);
        sum += arr[i];
    }

    min = arr[0];
    max = arr[0];
    
    // Find min and max
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    // Calculate the required sums
    long min_sum = sum - max;
    long max_sum = sum - min;

    printf("%ld %ld\n", min_sum, max_sum);

    return 0;
}