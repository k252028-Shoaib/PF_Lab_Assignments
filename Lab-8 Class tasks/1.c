#include <stdio.h>

int main(){
    int array[5][7], sum, highest = 0;
    float avg[5];
    //initialising the array
    for (int i = 0; i<5; i++){
        for (int j = 0; j<7; j++){
            printf("Please enter the temp for day %d for city %d: ",j+1,i+1);
            scanf(" %d", &array[i][j]);
        }
    }
    
    //display temp for each day and city
    printf("       ");
    for (int i = 1; i<=7;i++){
        printf(" Day %d |",i);
    }
    for (int i = 0; i<5; i++){
        printf("\nCity %d: ",i+1);
        for (int j = 0; j<7; j++){
            printf("%5d   ",array[i][j]);
        }
    }
    printf("\n");
    //finding the average
    for (int i = 0; i<5; i++){
        sum = 0;
        for (int j = 0; j<7; j++){
            sum += array[i][j];
        }
        avg[i] = (float)sum/7;
        printf("The average for city %d is %.2f\n", i+1, avg[i]);
    }
    //finding highest
    for (int i = 1; i<5; i++){
        if (avg[highest]<avg[i]) highest = i;
    }
    printf("The city with the highest weekly average temperature is city %d", highest+1);
    return 0;
}