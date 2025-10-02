#include <stdio.h>

int main(){
    int age = 0, balance = 0;

    printf("Enter you age: ");
    scanf("%d", &age);
    printf("Enter your balance: ");
    scanf("%d", &balance);

    if (age<21) printf("Not eligible for ride (underage)");
    else if (balance<200) printf("Not eligible (insufficient balance)");
    else printf("Eligible for ride");
    return 0;
}