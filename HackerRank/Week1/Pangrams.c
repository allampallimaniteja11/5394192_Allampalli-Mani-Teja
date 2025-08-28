#include <stdio.h>
#include <ctype.h>   // for tolower()

#define ALPHABET_COUNT 26

char* pangrams(const char* s) {
    static char result1[] = "pangram";
    static char result2[] = "not pangram";
    int seen[ALPHABET_COUNT] = {0};  // track letters
    
    // Traverse the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char ch = tolower(s[i]);
            seen[ch - 'a'] = 1;
        }
    }
    
    // Check if all letters are present
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (!seen[i]) {
            return result2;
        }
    }
    return result1;
}

int main() {
    char input[1000];
    
    // Read a full line (sentence)
    fgets(input, sizeof(input), stdin);
    
    printf("%s\n", pangrams(input));
    return 0;
}
