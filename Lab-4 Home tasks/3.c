#include <stdio.h>

int main() {
    int monthlyUsage;
    printf("Enter monthly water usage in liters: ");
    scanf("%d", &monthlyUsage);

    if (monthlyUsage <= 3000) {
        printf("No Fine\n");
    } else if (monthlyUsage <= 5000) {
        printf("Fine = 200 PKR\n");
    } else if (monthlyUsage <= 7000) {
        printf("Fine = 500 PKR\n");
    } else {
        printf("Fine = 1000 PKR + Water Supply Restricted\n");
    }

    return 0;
}
