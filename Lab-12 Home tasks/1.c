#include <stdio.h>
#include <stdlib.h>

void add(int **array, int *size, int *next_index);
void max_steps(int *array, int size);
void total_steps(int *array, int size);
void hours_above_threshold(int *array, int size, int threshold);
void save_to_file(int *array, int size);

int main(){
    int size = 0, next_index = 0/*indicates the next free index*/, choice;
    int* array = NULL;//starting with only 1 element
    int threshold;

    do
    {
        printf("Do you want to add a reading? (1 for yes and 0 for no): ");
        scanf(" %d", &choice);
        if (choice){
            add(&array, &size, &next_index);
        }
    } while (choice);
    
    max_steps(array, size);
    total_steps(array, size);

    printf("Enter the threshold: ");
    scanf(" %d", &threshold);
    hours_above_threshold(array, size, threshold);

    save_to_file(array, size);

    return 0;
}

void add(int **array, int *size, int *next_index){
    (*size)++;
    int *temp = realloc(*array, sizeof(int)*(*size));
    if (temp == NULL){
        printf("Reallocation failed\n");
    }
    *array = temp;
    printf("Enter the value of the reading: ");
    scanf(" %d", (*array)+(*next_index));
    (*next_index)++;
}

void max_steps(int *array, int size){
    int highest = 0;//assuming the most number of steps are in index 0
    for (int i = 0; i < size; i++){
        if (*(array+highest) < *(array+i)) highest = i;
    }
    printf("The max number of steps were %d in hour %d\n", *(array+highest), highest+1);
}

void total_steps(int *array, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += *(array+i);
    }
    printf("The total number of steps are %d\n", sum);
}

void hours_above_threshold(int *array, int size, int threshold){
    int amount = 0;
    for (int i = 0; i < size; i++){
        if (*(array+i) > threshold) amount++;
    }
    printf("There were %d hours with steps above the threshold of %d\n", amount, threshold);
}

void save_to_file(int *array, int size){
    FILE *fp = fopen("fitness_tracker.txt", "w");
    if (fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(fp, "----------- Fitness Tracker Data -----------\n");
    for (int i = 0; i < size; i++){
        fprintf(fp, "Reading %d: %d\n", i+1, *(array+i));
    }
    fclose(fp);
}