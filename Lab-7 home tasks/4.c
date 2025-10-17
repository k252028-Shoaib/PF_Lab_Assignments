#include <stdio.h>

int main (){
    int array[10], total = 0, no_of_flags = 0, i;

    //initialising the array
    for (i = 0; i<10; i++){
    	printf("Enter %dth house eletricity usage: ", i+1);
        scanf(" %d", &array[i]);
    }

    //Calculation etc
    for (i = 0; i<10; i++){
        if (array[i]<=200){
            printf("The bill for house %d is %d\n", i+1, array[i]*15);
            total += array[i]*15;
        }
        else if (array[i]<=500){
            printf("The bill for house %d is %d\n", i+1, array[i]*20);
            total += array[i]*20;
        }
        else {
            printf("The bill for house %d is %d\n", i+1, array[i]*25);
            total += array[i]*25;
            if (array[i]>700){
                no_of_flags++;
            }
        }
    }
    printf("The total revenue is %d and no of flagged houses is %d.", total, no_of_flags);
    return 0;
}