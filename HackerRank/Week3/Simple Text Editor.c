#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HISTORY 100000
#define MAX_STRING_LENGTH 100000

// A dynamic stack to store strings
char** history;
int top = -1;
int history_size = 0;

void push(const char* s) {
    if (top >= history_size - 1) {
        history_size = (history_size == 0) ? 10 : history_size * 2;
        history = (char**)realloc(history, history_size * sizeof(char*));
        if (history == NULL) {
            exit(EXIT_FAILURE);
        }
    }
    top++;
    history[top] = (char*)malloc(strlen(s) + 1);
    if (history[top] == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(history[top], s);
}

void pop(char* s) {
    if (top >= 0) {
        strcpy(s, history[top]);
        free(history[top]);
        top--;
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAX_STRING_LENGTH] = "";
    int type;

    history_size = 10;
    history = (char**)malloc(history_size * sizeof(char*));
    if (history == NULL) {
        return 1;
    }

    for (int i = 0; i < Q; i++) {
        scanf("%d", &type);

        if (type == 1) {
            char W[MAX_STRING_LENGTH];
            scanf("%s", W);
            push(S);
            strcat(S, W);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            push(S);
            S[strlen(S) - k] = '\0';
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (type == 4) {
            pop(S);
        }
    }

    for (int i = 0; i <= top; i++) {
        free(history[i]);
    }
    free(history);

    return 0;
}