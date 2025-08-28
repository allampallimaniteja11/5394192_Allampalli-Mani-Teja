#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPH 26
#define MAXLEN 100005

const char* isValid(char *s) {
    int freq[ALPH] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; ++i) freq[s[i] - 'a']++;

    int freqCount[MAXLEN] = {0};
    int maxfreq = 0;
    for (int i = 0; i < ALPH; ++i) {
        if (freq[i] > 0) {
            freqCount[freq[i]]++;
            if (freq[i] > maxfreq) maxfreq = freq[i];
        }
    }

    
    int distinct = 0;
    for (int f = 1; f <= maxfreq; ++f) {
        if (freqCount[f] > 0) distinct++;
    }

    if (distinct == 0) return "YES";   // empty string (edge) - treat as valid
    if (distinct == 1) return "YES";
    if (distinct > 2) return "NO";

    
    int f1 = 0, c1 = 0, f2 = 0, c2 = 0;
    for (int f = 1; f <= maxfreq; ++f) {
        if (freqCount[f] > 0) {
            if (f1 == 0) { f1 = f; c1 = freqCount[f]; }
            else { f2 = f; c2 = freqCount[f]; }
        }
    }

    
    if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return "YES";

    
    if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) return "YES";

    return "NO";
}

int main() {
    char s[MAXLEN];
    if (scanf("%100004s", s) != 1) return 0;
    printf("%s\n", isValid(s));
    return 0;
}