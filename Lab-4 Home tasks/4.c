#include <stdio.h>

int main() {
    int categoryCode;
    printf("Enter category code (1-4): ");
    scanf("%d", &categoryCode);

    switch (categoryCode) {
        case 1:
            printf("Low Usage Household\n");
            break;
        case 2:
            printf("Average Household\n");
            break;
        case 3:
            printf("High Usage Household\n");
            break;
        case 4:
            printf("Excessive Usage Household\n");
            break;
        default:
            printf("Invalid Category Code\n");
    }

    return 0;
}
