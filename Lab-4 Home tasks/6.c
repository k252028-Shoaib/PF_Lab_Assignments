#include <stdio.h>

int main() {
    int monthlyUsage, savedDays;

    printf("Enter monthly water usage in liters: ");
    scanf("%d", &monthlyUsage);

    printf("Enter number of days water was saved (< 80 liters/day): ");
    scanf("%d", &savedDays);

    if (monthlyUsage < 2500 && savedDays > 10) {
        printf("Bonus: 300 PKR Discount\n");
    } else {
        printf("No Bonus\n");
    }

    return 0;
}
