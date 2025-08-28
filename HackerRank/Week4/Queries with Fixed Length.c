#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXQ 105


typedef struct {
    int data[MAXN];
    int idx[MAXN];
    int front, back;
} Deque;

void initDeque(Deque *dq) {
    dq->front = dq->back = 0;
}

int isEmpty(Deque *dq) {
    return dq->front == dq->back;
}

void pushBack(Deque *dq, int val, int i) {
    while (dq->back > dq->front && val >= dq->data[dq->back - 1]) dq->back--;
    dq->data[dq->back] = val;
    dq->idx[dq->back] = i;
    dq->back++;
}

void popFront(Deque *dq, int i) {
    if (dq->front < dq->back && dq->idx[dq->front] == i) dq->front++;
}

int getFront(Deque *dq) {
    return dq->data[dq->front];
}

int main() {
    int n, q;
    static int arr[MAXN], queries[MAXQ];

    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < q; ++i) scanf("%d", &queries[i]);

    for (int kIdx = 0; kIdx < q; ++kIdx) {
        int d = queries[kIdx];
        Deque dq;
        initDeque(&dq);
        int minOfMax = 1000000000;

        for (int i = 0; i < n; ++i) {
            pushBack(&dq, arr[i], i);
            if (i >= d - 1) {
                int windowMax = getFront(&dq);
                if (windowMax < minOfMax) minOfMax = windowMax;
                popFront(&dq, i - d + 1);
            }
        }
        printf("%d\n", minOfMax);
    }
    return 0;
}