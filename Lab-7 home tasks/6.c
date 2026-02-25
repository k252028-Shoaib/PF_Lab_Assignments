#include <stdio.h>

int main (){
    int array[10], sum = 0, i, highest = 0;

    //initialising the array
    for (i = 0; i<10; i++){
    	printf("Enter %dth day's number of posts: ", i+1);
        scanf(" %d", &array[i]);
    }
    //I think "Weekly" activity summary is mis-typed in the question, I will treat it as summary for all 10 days
    printf("Activity summary:\n");

    //Calculation. If there are days with same highest acitivity, I will output only 1
    for (i = 0; i<10; i++){
        if (array[highest] < array[i]) highest = i;
        sum += array[i];
    }
    printf("The day with the highest activity is: %d\n", highest+1); //days are from 1-10 so highest + 1
    printf("The average number of posts are: %.2f\n", (float)sum/10);

    //Detecting streak
    for (i=0; i<8;i++){
        if (array[i]<array[i+1] && array[i+1]<array[i+2]){
            printf("The days %d, %d, %d are three consecutive increasing days\n", i+1, i+2, i+3);
        }
    }
    return 0;
}