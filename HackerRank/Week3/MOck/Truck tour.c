#include <stdio.h>

int truckTour(int petrolpumps[][2], int n) {
    int start = 0, fuel = 0;
    for (int i = 0; i < n; i++) {
        fuel += petrolpumps[i][0] - petrolpumps[i][1];
        if (fuel < 0) {
            start = i + 1;
            fuel = 0;
        }
    }
    return start;
}

int main() {
    int n;
    scanf("%d", &n);

    int petrolpumps[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &petrolpumps[i][0], &petrolpumps[i][1]);
    }

    int result = truckTour(petrolpumps, n);
    printf("%d\n", result);

    return 0;
}
