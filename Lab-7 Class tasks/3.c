#include <stdio.h>

int main (){
    int array[8], i, total=0, count=0;
    char category;

    //initialising the array
    for (i = 0; i<8; i++){
    	printf("Enter %dth passenger's baggage weight (in kg): ", i+1);
        scanf(" %d", &array[i]);
    }
    //Calculation
    for (i = 0; i<8; i++){

        if (array[i]<=20){
            printf("The %d passenger has baggage of weight %d and it is is in the category of 0-20kg so it has no fine\n", i+1, array[i]);
        }
        else if (array[i]<=30){
            printf("The %d passenger has baggage of weight %d and it is is in the category of 21-30kg so it has a fine of 500\n", i+1, array[i]);
            total += 500;
        }
        else {
            printf("The %d passenger has baggage of weight %d and it is is in the category of 30kg+ so it has a fine of 1000 and will be inspected\n", i+1, array[i]);
            total += 1000;
            count++;
        }
    }
    printf("The total fine for all passengers is %d\n", total);
    printf("The number of flagged bags are %d", count);

    return 0;
}