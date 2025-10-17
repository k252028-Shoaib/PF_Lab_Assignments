#include <stdio.h>

int main (){
    float array[10], total = 0.0;
    int i;

    //initialising the array
    for (i = 0; i<10; i++){
    	printf("Enter %dth product's price: ", i+1);
        scanf(" %f", &array[i]);
    }

    //Calculation
    for (i = 0; i<10; i++){

        if (array[i]<1000){
            array[i] *= 0.95;
            printf("The discounted price for item %d is %.2f\n", i+1, array[i]);
            total += array[i];
        }
        else if (array[i]<5000){
            array[i] *= 0.90;
            printf("The discounted price for item %d is %.2f\n", i+1, array[i]);
            total += array[i];
        }
        else {
            array[i] *= 0.85;
            printf("The discounted price for item %d is %.2f\n", i+1, array[i]);
            total += array[i];
        }
    }
    printf("Your total after discounts is: %.2f\n", total);
    if (total>25000){
        printf("You got a Gold voucher!");
    }
    return 0;
}