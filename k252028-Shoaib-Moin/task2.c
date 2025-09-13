#include <stdio.h>

int main() {
    float subtotal, tax, total, eggs, bread, butter = 0.0f;
    float tax_rate = 0.17f;   // 17%

    // Input item prices
    printf("Enter price of eggs: ");
    scanf("%f", &eggs);

    printf("Enter price of bread: ");
    scanf("%f", &bread);

    printf("Enter price of butter: ");
    scanf("%f", &butter);

    // Calculate subtotal, tax, and total
    subtotal = eggs + bread + butter;
    tax = subtotal * tax_rate;
    total = subtotal + tax;

    // Print receipt
    printf("---------------------------\n     Shopping Receipt     \n---------------------------\n");
    printf("Eggs   : %.2f\n", eggs);
    printf("Bread  : %.2f\n", bread);
    printf("Butter : %.2f\n", butter);
    printf("---------------------------\n");
    printf("Subtotal : %.2f\n", subtotal);
    printf("Tax (17%%): %.2f\n", tax);
    printf("---------------------------\n");
    printf("Grand Total : %.2f\n", total);
    printf("---------------------------\n");

    return 0;
}
