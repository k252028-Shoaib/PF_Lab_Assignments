#include <stdio.h>

int main (){
    int  count = 0, i;
    float array[8];
    //initialising the array
    for (i = 0; i<8; i++){
    	printf("Enter %dth vehicle's mileage (km/l): ", i+1);
        scanf(" %f", &array[i]);
    }

    //Calculation etc
    for (i = 0; i<8; i++){
        if (array[i]>=18){
            printf("Car %d is efficient\n", i+1);
        }
        else if (array[i]>=12){
            printf("Car %d is average\n", i+1);
        }
        else {
            printf("Car %d is need maintenance\n", i+1);
            count++;
        }
    }
    if (count> 3) printf("Fleet Efficiency Alert!");
    return 0;
}