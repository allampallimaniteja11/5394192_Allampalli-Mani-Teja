#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

long long heap[MAX];
int size = 0;


void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}


void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void heapifyDown(int i) {
    int left, right, smallest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}


void insert(long long val) {
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}


long long extractMin() {
    if (size == 0) return -1;
    long long minVal = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return minVal;
}


int cookies(int k, int n) {
    int operations = 0;

    while (size > 1 && heap[0] < k) {
        long long least = extractMin();
        long long second = extractMin();

        long long newCookie = least + 2 * second;
        insert(newCookie);
        operations++;
    }

    if (heap[0] >= k) return operations;
    else return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        long long sweetness;
        scanf("%lld", &sweetness);
        insert(sweetness);
    }

    int result = cookies(k, n);
    printf("%d\n", result);

    return 0;
}