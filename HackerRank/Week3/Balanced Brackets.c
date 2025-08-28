#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '0';
    return stack[top];
}

int isBalanced(char *s) {
    top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else {
            char ch = pop();
            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if (isBalanced(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
