#include <stdio.h>
#include <stdlib.h>

int sort_func(const void *x, const void *y){
    return (*(int*)x - *(int*)y);
}

int calculate_min_difference(int window_size, int numbers[], int total_count){
    qsort(numbers, total_count, sizeof(int), sort_func);
    int min_difference = __INT_MAX__;
    for(int start = 0; start <= total_count - window_size; start++){
        int current_diff = numbers[start + window_size - 1] - numbers[start];
        if(current_diff < min_difference) min_difference = current_diff;
    }
    return min_difference;
}

int main(){
    int total_elements, subset_size;
    scanf("%d%d", &total_elements, &subset_size);
    int data_array[total_elements];
    for(int i = 0; i < total_elements; i++) scanf("%d", &data_array[i]);
    printf("%d", calculate_min_difference(subset_size, data_array, total_elements));
    return 0;
}
