#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) return len1 - len2;
    return strcmp(str1, str2);
}

int main() {
    int n;
    scanf("%d\n", &n);

    char *arr[n];
    char buffer[101]; // Adjust size if numbers are bigger

    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
        arr[i] = strdup(buffer); // Allocate memory for each string
    }

    qsort(arr, n, sizeof(char *), compare);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]); // Free allocated memory
    }

    return 0;
}
