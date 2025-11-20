#include <stdio.h>
#include <string.h>
typedef struct Customer {
    char name[50];
    int meterID;
    int units;
    float bill;
} Customer;


float taxCalc(int units) {
    if (units <= 0){
        return 0;
    }


    if (units <= 100){
        return units * 0.05 + taxCalc(0);
    }
    if (units <= 300){
        return 100 * 0.05 + (units - 100) * 0.12;
    }

    /* above 300 */
    return 100 * 0.05 + 200 * 0.12 + (units - 300) * 0.18;
}


int main() {
    Customer c;
    float rate;

    printf("Enter name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter meter ID: ");
    scanf("%d", &c.meterID);

    printf("Enter units: ");
    scanf("%d", &c.units);

    printf("Enter price per unit: ");
    scanf("%f", &rate);

    float base = c.units * rate;
    float tax = taxCalc(c.units);
    c.bill = base + tax;

    printf("Final Bill = %.2f", c.bill);
    return 0;
}