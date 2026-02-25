#include <stdio.h>

float average_f(int *ptr);
int max_day_f(int *ptr);    

int main(){
    int data[7] = {0};
    int count = 0;

    //inputting the data
    for (int i = 0; i < 7; i++){
        printf("Enter rainfall data in millimetres for day %d: ", i+1);
        scanf(" %d", &data[i]);
    }

    float average = average_f(data);
    int day = max_day_f(data);

    for (int i = 0; i<7; i++){
        if (data[i] > average) count++;
    }

    printf("The average rainfall throughout the week was %.1f mm\n", average);
    printf("The day with the highest rainfall was %d\n", day);
    if (count > 3) printf("Rainy Week\n");
    else printf("Normal Week\n");
    return 0;
}

float average_f(int *ptr){
    int sum = 0;
    float average;
    for (int i = 0; i < 7; i++){
        sum += *(ptr + i);
    }
    average = (float)sum / 7;
    return average;
}

int max_day_f(int *ptr){
    int day = 0;
    for (int i = 0; i < 7; i++){
        if (*(ptr + day) < *(ptr + i)) day = i;
    }
    return (day+1);
}