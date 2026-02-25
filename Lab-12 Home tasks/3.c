#include <stdio.h>
#include <stdlib.h>

void save_to_file(float *array, int size, float high, float low, int alerts, int threshold);
void find_extremes(float *array, int size, float *high, float *low);
int count_alerts(float *array, int size, int threshold);

int main(){
    float *array = (float*) malloc(sizeof(float)*1);
    int tail = 0;
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Enter temperature reading: ");
        scanf(" %f", array+tail);

        printf("Do you want to add another reading? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if(choice){
            tail++;
            float *temp = realloc(array, sizeof(float)*(tail+1));
            if(temp == NULL){
                printf("Memory re-allocation failed\n");
                free(array);
                return 1;
            }
            array = temp;
        }
    } while (choice);

    int threshold;
    printf("Enter alert threshold temperature: ");
    scanf(" %d", &threshold);

    float high, low;
    find_extremes(array, tail+1, &high, &low);
    int alerts = count_alerts(array, tail+1, threshold);

    save_to_file(array, tail+1, high, low, alerts, threshold);
    free(array);
    return 0;
}

void find_extremes(float *array, int size, float *high, float *low){
    *high = *array;
    *low = *array;
    for(int i=1; i<size; i++){
        if(*(array+i) > *high) *high = *(array+i);
        if(*(array+i) < *low) *low = *(array+i);
    }
}

int count_alerts(float *array, int size, int threshold){
    int count = 0;
    for(int i=0; i<size; i++){
        if(*(array+i) > threshold) count++;
    }
    return count;
}

void save_to_file(float *array, int size, float high, float low, int alerts, int threshold){
    printf("Saving data to file...\n");
    FILE *fp = fopen("temperature_summary.txt", "w");
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(fp, "----------- Temperature Report -----------\n");
    for(int i=0; i<size; i++){
        fprintf(fp, "Reading %d: %.2f\n", i+1, *(array+i));
    }
    fprintf(fp, "------------------------------------------\n");
    fprintf(fp, "Highest: %.2f\nLowest: %.2f\n", high, low);
    fprintf(fp, "Readings above %d: %d\n", threshold, alerts);

    printf("Data saved successfully to temperature_summary.txt\n");
    fclose(fp);
}