#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int size = 0;


void swap(int *a, int *b) {
    int temp = *a;
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
        } else {
            break;
        }
    }
}


void insert(int val) {
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

void delete(int val) {
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i] == val) {
            break;
        }
    }
    if (i == size) return; // not found

    heap[i] = heap[size - 1];
    size--;

    heapifyUp(i);
    heapifyDown(i);
}

int getMin() {
    return heap[0];
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type, v;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &v);
            insert(v);
        } else if (type == 2) {
            scanf("%d", &v);
            delete(v);
        } else if (type == 3) {
            printf("%d\n", getMin());
        }
    }

    return 0;
}