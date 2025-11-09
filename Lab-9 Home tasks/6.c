#include <stdio.h>

void calculate_total(float (*array)[3]);

void apply_discount(float (*array)[3]);
 
int main(){
    float data[5][3]; // 3 columns for price, quantity, total (price * quantity)

    //inputting data
    for (int i = 0; i < 5; i++){
        printf("Enter price for book %d: ", i+1);
        scanf(" %f", &data[i][0]);
        
        printf("Enter quantity in stock for book %d: ", i+1);
        scanf(" %f", &data[i][1]);
    }
    
    calculate_total(data);

    void (*discount_ptr)(float (*array)[3]);
    discount_ptr = &apply_discount;
    discount_ptr(data);

    return 0;
}

void calculate_total(float (*array)[3]){
    for (int i = 0; i < 5; i++){
        *(*(array + i) + 2) = (*(*(array + i) + 0)) * (*(*(array + i) + 1));
    }
}

void apply_discount(float (*array)[3]){
    for(int i = 0; i < 5; i++){
        if (*(*(array + i) + 1) > 5) *(*(array + i) + 2) *= 0.8;
        else if (*(*(array + i) + 1) >= 3) *(*(array + i) + 2) *= 0.9;
        printf("The total value of book %d is %.2f\n", i+1, *(*(array + i) + 2));
    }
}