#include <stdio.h>
#define MAXN 200000
#define MAXM 200000

int ranked[MAXN];
int player[MAXM];
int unique[MAXN];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &ranked[i]);
    }
    
    int ulen = 0;
    unique[ulen++] = ranked[0];
    for (int i=1; i<n; i++) {
        if (ranked[i] != ranked[i-1]) {
            unique[ulen++] = ranked[i];
        }
    }
    scanf("%d", &m);
    for (int j=0; j<m; j++) {
        scanf("%d", &player[j]);
    }

    int i = ulen-1;
    for (int j=0; j<m; j++) {
        while (i >= 0 && player[j] >= unique[i]) {
            i--;
        }
        printf("%d\n", i+2); // +2 because rank is (i+1, and 1-based)
    }
    return 0;
}