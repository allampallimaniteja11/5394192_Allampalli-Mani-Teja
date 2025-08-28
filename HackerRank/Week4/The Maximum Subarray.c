#include <stdio.h>

#define MAXN 100000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int t, n;
    int arr[MAXN];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        
        int cur_max = arr[0], max_sum = arr[0];
        for (int i = 1; i < n; i++) {
            cur_max = max(arr[i], cur_max + arr[i]);
            if (cur_max > max_sum) max_sum = cur_max;
        }

        
        int subseq_sum = 0, exist_positive = 0, max_elem = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                subseq_sum += arr[i];
                exist_positive = 1;
            }
            if (arr[i] > max_elem) max_elem = arr[i];
        }
        if (!exist_positive)
            subseq_sum = max_elem;

        printf("%d %d\n", max_sum, subseq_sum);
    }
    return 0;
}
