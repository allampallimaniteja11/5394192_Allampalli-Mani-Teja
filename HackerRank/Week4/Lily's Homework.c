#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int index;
} Pair;

int cmpAsc(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return (p1->value - p2->value);
}
int cmpDesc(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return (p2->value - p1->value);
}
int minSwaps(int *arr, Pair *pairs, int n) {
    int *visited = (int*)calloc(n, sizeof(int));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].index == i) continue;
        int cycle = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].index;
            cycle++;
        }
        if (cycle > 0) ans += (cycle - 1);
    }
    free(visited);
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Pair *pairsAsc = (Pair*)malloc(n * sizeof(Pair));
    Pair *pairsDesc = (Pair*)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairsAsc[i].value = arr[i];
        pairsAsc[i].index = i;
        pairsDesc[i].value = arr[i];
        pairsDesc[i].index = i;
    }

    qsort(pairsAsc, n, sizeof(Pair), cmpAsc);
    qsort(pairsDesc, n, sizeof(Pair), cmpDesc);

    int minSwapsAsc = minSwaps(arr, pairsAsc, n);
    int minSwapsDesc = minSwaps(arr, pairsDesc, n);

    printf("%d\n", minSwapsAsc < minSwapsDesc ? minSwapsAsc : minSwapsDesc);

    free(arr);
    free(pairsAsc);
    free(pairsDesc);
    return 0;
}