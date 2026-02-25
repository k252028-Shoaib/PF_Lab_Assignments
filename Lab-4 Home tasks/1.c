#include <stdio.h>

int main() {
    float dailyUsage;
    printf("Enter daily water usage in liters: ");
    scanf("%f", &dailyUsage);

    if (dailyUsage <= 100) {
        printf("Efficient Usage\n");
    } else {
        printf("High Usage Detected\n");
    }

    return 0;
}
