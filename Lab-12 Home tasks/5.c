#include <stdio.h>
#include <stdlib.h>

void save_to_file(int *array, int size, int rate);

int main(){
    int *array = (int*) malloc(sizeof(int)*1); // storing durations in hours
    int tail = 0;
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Enter rental duration (in hours): ");
        scanf(" %d", array+tail);

        printf("Do you want to add another rental? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if(choice){
            tail++;
            int *temp = realloc(array, sizeof(int)*(tail+1));
            if(temp == NULL){
                printf("Memory re-allocation failed\n");
                free(array);
                return 1;
            }
            array = temp;
        }
    } while (choice);

    int rate;
    printf("Enter hourly rate for cost calculation: ");
    scanf(" %d", &rate);

    save_to_file(array, tail+1, rate);
    free(array);
    return 0;
}

void save_to_file(int *array, int size, int rate){
    printf("Saving data to file...\n");
    FILE *fp = fopen("Rental_Invoices.txt", "w");
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    int total_time = 0;
    int max_duration = 0;

    fprintf(fp, "----------- Rental Invoices -----------\n");
    for(int i=0; i<size; i++){
        int cost = *(array+i) * rate;
        total_time += *(array+i);
        if(*(array+i) > max_duration) max_duration = *(array+i);
        
        fprintf(fp, "Customer %d | Duration: %d hrs | Cost: %d\n", i+1, *(array+i), cost);
    }
    fprintf(fp, "---------------------------------------\n");
    fprintf(fp, "Total Rental Time: %d hrs\n", total_time);
    fprintf(fp, "Highest Rental Duration: %d hrs\n", max_duration);

    printf("Data saved successfully to Rental_Invoices.txt\n");
    fclose(fp);
}