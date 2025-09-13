#include <stdio.h>

int main() {
    char name[50] = "";
    int units = 0;
    float price_per_unit, total = 0.0f;

    //Get cutomer Namwe
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);

    //Get Number of units consumed
    printf("How many units were consumed? ");
    scanf("%d", &units);

    //Get price per unit
    printf("What is the price per unit? ");
    scanf("%f", &price_per_unit);

    //Calculate Total
    total = units * price_per_unit;

    //Output
    printf("-------------------------------\n     ELECTRICITY BILL     \n-------------------------------\n");
    printf("Customer: %s", name);
    printf("Units consumed: %d\n", units);
    printf("Price per unit: %.2f\n", price_per_unit);
    printf("-------------------------------\n");
    printf("Total bill: %.2f PKR\n", total);
    printf("-------------------------------\n");

    return 0;
}
