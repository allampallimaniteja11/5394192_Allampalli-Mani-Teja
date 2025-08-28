#include <stdio.h>

int find_unique(int count, int* arr) {
    int unique_val = 0;
    for (int i = 0; i < count; i++) {
        unique_val ^= arr[i];
    }
    return unique_val;
}

int main() {
    int array_size;
    scanf("%d", &array_size);
    int numbers[array_size];
    
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int result = find_unique(array_size, numbers);
    printf("%d\n", result);
    
    return 0;
}
