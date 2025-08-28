#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

void createStack(Stack* s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->items = (int*)malloc(capacity * sizeof(int));
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    s->items[++s->top] = item;
}

int pop(Stack* s) {
    return s->items[s->top--];
}

void getPrimes(int* primes, int limit) {
    bool* isPrime = (bool*)malloc((limit + 1) * sizeof(bool));
    memset(isPrime, true, (limit + 1) * sizeof(bool));
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    int primeIndex = 0;
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes[primeIndex++] = p;
        }
    }
    free(isPrime);
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    int prime_limit = 100000;
    int* primes = (int*)malloc(prime_limit * sizeof(int));
    getPrimes(primes, prime_limit);

    Stack A, B, A_prime;
    createStack(&A, number_count);
    createStack(&B, number_count);
    createStack(&A_prime, number_count);

    for (int i = number_count - 1; i >= 0; i--) {
        push(&A, number[i]);
    }

    int* result = (int*)malloc(number_count * sizeof(int));
    int result_index = 0;

    for (int i = 0; i < q; i++) {
        int current_prime = primes[i];
        while (!isEmpty(&A)) {
            int plate = pop(&A);
            if (plate % current_prime == 0) {
                push(&B, plate);
            } else {
                push(&A_prime, plate);
            }
        }
        while (!isEmpty(&B)) {
            result[result_index++] = pop(&B);
        }
        A = A_prime;
        createStack(&A_prime, number_count);
    }
    
    while (!isEmpty(&A)) {
        result[result_index++] = pop(&A);
    }
    
    *result_count = result_index;
    
    free(A.items);
    free(B.items);
    free(A_prime.items);
    free(primes);

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int q = parse_int(*(first_multiple_input + 1));

    char** number_temp = split_string(rtrim(readline()));

    int* number = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int number_item = parse_int(*(number_temp + i));

        *(number + i) = number_item;
    }

    int result_count;
    int* result = waiter(n, number, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}