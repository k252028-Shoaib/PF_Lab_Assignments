#include <stdio.h>

int main (){
    int array[10];
    int count = 0, total = 0, i;

    //initialising the array
    for (i = 1; i<=10; i++){
    	printf("Enter %dth value \n", i);
        scanf(" %d", &array[i]);
    }

    //Calculation
    for (i = 1; i<=10; i++){

        if (array[i]<=2){
            printf("The fees for car %d is %d\n", i, array[i]*50);
            total += array[i]*50;
        }
        else if (array[i]<=5){
            printf("The fees for car %d is %d\n", i, array[i]*40);
            total += array[i]*40;
        }
        else {
            printf("The fees for car %d is %d\n", i, array[i]*30);
            total += array[i]*30;
        }
        if (array[i]> 8){
            printf("Overstay Warning\n");
            count++;
        }
    }
    
    printf("\nThe total revenue is %d\n", total);
    printf("The number of cars over staying are %d", count);
    return 0;
}