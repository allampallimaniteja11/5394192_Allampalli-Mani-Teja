#include <stdio.h>
#include <stdint.h>

// Function to flip all bits of a 32-bit unsigned integer
unsigned int flipBits(unsigned int n) {
    // 0xFFFFFFFF is a 32-bit mask with all bits = 1
    return ~n & 0xFFFFFFFF;
}

int main() {
    int queries;
    scanf("%d", &queries);

    while (queries--) {
        unsigned int num;
        scanf("%u", &num);
        unsigned int result = flipBits(num);
        printf("%u\n", result);
    }

    return 0;
}
