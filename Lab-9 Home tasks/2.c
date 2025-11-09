#include <stdio.h>
// it is assumed that the question asks to apply discount on each product and not on total

float discount_applier(float *price, float *discounted_price);

int main(){
    float price[5] = {0.0};
    float discounted_price[5] = {0.0};

    //inputting the initial prices 
    for (int i = 0; i < 5; i++){
        printf("Eneter the price for product %d: ", i+1);
        scanf(" %f", &price[i]);
    }

    float total = discount_applier(price, discounted_price);
    float *ptr = &total;
    printf("The total discounted price is %.1f\n", *ptr);

    return 0;
}

float discount_applier(float *price, float *discounted_price){
    float total = 0.0;
    for (int i = 0; i<5; i++){
        if (*(price + i) < 1000) *(discounted_price + i) = (*(price + i)) * 0.9; //10% discount
        else if (*(price + i) < 5000) *(discounted_price + i) = (*(price + i)) * 0.85; //15% discount
        else *(discounted_price + i) = (*(price + i)) * 0.75; //25% discount
        total += *(discounted_price + i);
    }
    return total;
}