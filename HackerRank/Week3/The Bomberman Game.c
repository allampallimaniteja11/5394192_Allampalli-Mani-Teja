#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void fill_grid(char **g, int R, int C) {
    for (int i = 0; i < R; ++i) {
        memset(g[i], 'O', C);
        g[i][C] = '\0';
    }
}

static char **allocate_grid(int R, int C) {
    char **g = (char **)malloc(R * sizeof(char *));
    for (int i = 0; i < R; ++i) {
        g[i] = (char *)malloc((C + 1) * sizeof(char));
        g[i][C] = '\0';
    }
    return g;
}

static void deallocate_grid(char **g, int R) {
    for (int i = 0; i < R; ++i) free(g[i]);
    free(g);
}

static char **detonate_grid(char **cur, int R, int C) {
    static const int dx[4] = {-1, 1, 0, 0};
    static const int dy[4] = {0, 0, -1, 1};

    int **marked = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; ++i) {
        marked[i] = (int *)calloc(C, sizeof(int));
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (cur[r][c] == 'O') {
                marked[r][c] = 1;
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dx[k], nc = c + dy[k];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                        marked[nr][nc] = 1;
                    }
                }
            }
        }
    }

    char **next = allocate_grid(R, C);
    fill_grid(next, R, C);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (marked[r][c]) next[r][c] = '.';
        }
    }

    for (int i = 0; i < R; ++i) free(marked[i]);
    free(marked);
    return next;
}

int main(void) {
    int R, C;
    long long N;
    if (scanf("%d %d %lld", &R, &C, &N) != 3) return 0;

    char **start = allocate_grid(R, C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", start[i]);
    }

    if (N == 1) {
        for (int i = 0; i < R; ++i) puts(start[i]);
        deallocate_grid(start, R);
        return 0;
    }

    if (N % 2 == 0) {
        char **full = allocate_grid(R, C);
        fill_grid(full, R, C);
        for (int i = 0; i < R; ++i) puts(full[i]);
        deallocate_grid(full, R);
        deallocate_grid(start, R);
        return 0;
    }

    char **A = detonate_grid(start, R, C);
    if ((N - 3) % 4 == 0) {
        for (int i = 0; i < R; ++i) puts(A[i]);
        deallocate_grid(A, R);
        deallocate_grid(start, R);
        return 0;
    }

    char **B = detonate_grid(A, R, C);
    for (int i = 0; i < R; ++i) puts(B[i]);

    deallocate_grid(B, R);
    deallocate_grid(A, R);
    deallocate_grid(start, R);
    return 0;
}