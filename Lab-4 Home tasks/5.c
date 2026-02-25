#include <stdio.h>

int main() {
    int familyMembers;
    int monthlyUsage;

    printf("Enter number of family members: ");
    scanf("%d", &familyMembers);

    printf("Enter monthly water usage in liters: ");
    scanf("%d", &monthlyUsage);

    if (monthlyUsage > 3000) {
        if (familyMembers > 6) {
            printf("Allowed: Large Family Exception\n");
        } else {
            printf("Fine Applied\n");
        }
    } else {
        printf("No fine or exception\n");
    }

    return 0;
}
