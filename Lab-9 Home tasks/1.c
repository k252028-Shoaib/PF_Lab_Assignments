#include <stdio.h>

int count(int amount, int *ptr);

int main(){
    int wihtdraw = 0;
    int array[3] = {0}; // element 0 = no. of notes of Rs5000, element 1 = Rs 1000, element 2 = RS500; 

    printf("Enter the amount you want to withdraw: ");
    scanf(" %d", &wihtdraw);

    int remaining = count(wihtdraw, array);

    if (wihtdraw % 50 == 0){
        printf("The withdraw amount is divisible by 50\n");
    }
    
    //Outputs
    printf("Amount withdrawed is %d\n", wihtdraw - remaining);
    if (remaining > 0) printf("Returned amount : %d\n", remaining);    
    if (array[0] > 0) printf("You got %d Rs.5000 notes\n", array[0]);
    if (array[1] > 0) printf("You got %d Rs.1000 notes\n", array[1]);
    if (array[2] > 0) printf("You got %d Rs.500 notes\n", array[2]);
    return 0;
}

int count(int amount, int *ptr){
    *ptr = amount/5000;
    amount %= 5000;
    *(ptr + 1) = amount/1000;
    amount %= 1000;
    *(ptr + 2) = amount/500;
    amount %= 500;
    return amount;
}