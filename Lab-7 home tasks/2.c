#include <stdio.h>

int main (){
    int array[7], total = 0, i;

    //initialising the array
    for (i = 0; i<7; i++){
    	printf("Enter %dth ward's number of patients: ", i+1);
        scanf(" %d", &array[i]);
    }

    //Calculation
    for (i = 0; i<7; i++){
        total += array[i];
        if (array[i]>10){
            printf("The %dth ward is overcrowded and needs administrative review\n", i+1);
        }
        else if (array[i]>=6){
            printf("The %dth ward is Stable\n", i+1);
        }
        else {
            printf("The %dth ward is underutilised and needs administrative review\n", i+1);
        }
    }
    printf("The total number of patients is: %d", total);
    return 0;
}