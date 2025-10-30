#include <stdio.h>

void calculate(int units[], float *ptr);

int main(){
    int units[10]; //for 10 houses
    float bill[10]; //for 10 houses
    float sum = 0.0;

    //inputting and calculating
    for (int i = 0; i < 10; i++){
        printf("Enter the units consumed for house %d (in kwh): ", i+1);
        scanf(" %d", &units[i]);
    }
    calculate(units, bill);
    printf("\n");

    //calculating sum
    for (int i = 0; i < 10; i++){
        sum += bill[i];
    }

    printf("The total revenue collected by the energy company is %.2f\n", sum);
    return 0;
}

void calculate(int units[], float *ptr){
    for (int i = 0; i < 10; i++){
        if (units[i] > 100)
            *ptr = (100 * 10.0) + ((units[i] - 100) * 15.0);
        else 
            *ptr = (float) units[i] * 10.0;
        ptr++;
    }
    
}