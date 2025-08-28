#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void find_occurrences(char input_strs[][MAX_LEN], int num_strs, char query_strs[][MAX_LEN], int num_queries, int counts[]) {
    for (int i = 0; i < num_queries; i++) {
        counts[i] = 0;
        for (int j = 0; j < num_strs; j++) {
            if (strcmp(query_strs[i], input_strs[j]) == 0) {
                counts[i]++;
            }
        }
    }
}

int main() {
    int num_strs, num_queries;

    scanf("%d", &num_strs);
    char input_strs[num_strs][MAX_LEN];

    for (int i = 0; i < num_strs; i++) {
        scanf("%s", input_strs[i]);
    }

    scanf("%d", &num_queries);
    char query_strs[num_queries][MAX_LEN];

    for (int i = 0; i < num_queries; i++) {
        scanf("%s", query_strs[i]);
    }

    int counts[num_queries];

    find_occurrences(input_strs, num_strs, query_strs, num_queries, counts);

    for (int i = 0; i < num_queries; i++) {
        printf("%d\n", counts[i]);
    }

    return 0;
}
