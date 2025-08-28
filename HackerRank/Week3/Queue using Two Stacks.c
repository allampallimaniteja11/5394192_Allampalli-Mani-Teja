#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

void init(Stack *s, int cap) {
    s->capacity = cap;
    s->top = -1;
    s->arr = (int*)malloc(cap * sizeof(int));
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int peek(Stack *s) {
    return s->arr[s->top];
}

typedef struct {
    Stack s1, s2;
} Queue;

void enqueue(Queue *q, int x) {
    push(&q->s1, x);
}

void dequeue(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (!isEmpty(&q->s2)) pop(&q->s2);
}

int front(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return peek(&q->s2);
}

int main() {
    int q, type, x;
    scanf("%d", &q);
    Queue queue;
    init(&queue.s1, q);
    init(&queue.s2, q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            enqueue(&queue, x);
        } else if (type == 2) {
            dequeue(&queue);
        } else if (type == 3) {
            printf("%d\n", front(&queue));
        }
    }
    free(queue.s1.arr);
    free(queue.s2.arr);
    return 0;
}
