#include <stdio.h>

// Function to get category name based on code
const char* getCategoryName(int code) {
    switch (code) {
        case 1: return "Low Usage Household";
        case 2: return "Average Household";
        case 3: return "High Usage Household";
        case 4: return "Excessive Usage Household";
        default: return "Invalid Category Code";
    }
}

// Function to calculate bill based on usage
int calculateBill(int usage) {
    if (usage <= 3000) return 500;
    else return 1000;
}

// Function to calculate fine based on usage
int calculateFine(int usage) {
    if (usage <= 3000) return 0;
    else if (usage <= 5000) return 200;
    else if (usage <= 7000) return 500;
    else return 1000;
}

// Function to check fine message for very high usage
const char* fineMessage(int usage) {
    if (usage > 7000) return " + Water Supply Restricted";
    else return "";
}

// Function to check family exception or fine
const char* familyExceptionOrFine(int usage, int familyMembers) {
    if (usage > 3000) {
        if (familyMembers > 6) {
            return "Allowed: Large Family Exception";
        } else {
            return "Fine Applied";
        }
    }
    return "No fine or exception";
}

// Function to check bonus eligibility
const char* checkBonus(int usage, int savedDays) {
    if (usage < 2500 && savedDays > 10) {
        return "Bonus: 300 PKR Discount";
    }
    return "No Bonus";
}

int main() {
    int categoryCode, monthlyUsage, familyMembers, savedDays;
    int bill, fine;
    const char* categoryName;
    const char* familyStatus;
    const char* bonus;

    // Input from user
    printf("Enter monthly water usage in liters: ");
    scanf("%d", &monthlyUsage);

    printf("Enter family size: ");
    scanf("%d", &familyMembers);

    printf("Enter category code (1-4): ");
    scanf("%d", &categoryCode);

    printf("Enter number of days water was saved (<80 liters/day): ");
    scanf("%d", &savedDays);

    // Get category name
    categoryName = getCategoryName(categoryCode);

    // Calculate bill
    bill = calculateBill(monthlyUsage);

    // Calculate fine
    fine = calculateFine(monthlyUsage);

    // Family exception or fine check
    familyStatus = familyExceptionOrFine(monthlyUsage, familyMembers);

    // Bonus check
    bonus = checkBonus(monthlyUsage, savedDays);

    // Output results
    printf("\nCategory: %s\n", categoryName);
    printf("Bill = %d PKR\n", bill);

    if (fine > 0) {
        printf("Fine = %d PKR%s\n", fine, fineMessage(monthlyUsage));
    } else {
        printf("Fine = No Fine\n");
    }

    printf("%s\n", familyStatus);
    printf("%s\n", bonus);

    return 0;
}
