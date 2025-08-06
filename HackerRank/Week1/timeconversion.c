#include <stdio.h>
#include <string.h>

int main() {
    char s[11];
    int hour, minute, second;
    char period[3];

    // Read input as string
    scanf("%s", s);

    // Parse input: hour, minute, second, AM/PM
    sscanf(s, "%2d:%2d:%2d%2s", &hour, &minute, &second, period);

    // Convert to 24-hour format
    if (strcmp(period, "PM") == 0 && hour != 12) {
        hour += 12;
    }
    if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0;
    }

    // Print in 24-hour format (with leading zeroes)
    printf("%02d:%02d:%02d\n", hour, minute, second);

    return 0;
}