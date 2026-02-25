#include <stdio.h>
#include <stdlib.h>

void save_to_file(int *array, int size, float average, float bill);

int main(){
    int* array = (int*)malloc(sizeof(int)*1);//starting with the size of 1 day
    if(array == NULL){
        printf("Failed to allocate memory\n");
        return 1;
    }
    
    int choice, total = 0, tail = 0/*tells the index of the last element. ALso tells the size but by 1 less*/;
    do
    {
        printf("Enter units consumed on day %d: ", tail+1);
        scanf(" %d", array+tail);

        total += *(array+tail);

        printf("Do you want to continue? (1 for yes and 0 for no): ");
        scanf(" %d", &choice);
        if(choice){
            tail++;
            int* temp = realloc(array, sizeof(int)*(tail+1));
            if(temp == NULL){
                printf("Failed to re-allocate memory\n");
                free(array); //free the original array before exiting
                return 1;
            }
            array = temp;
        }
    } while (choice);
    
    float average, bill;
    average = (float)total/(tail+1); // tail + 1 is the size (number of days)
    if(total<100) bill = (float)total*50;
    else if(total<300) bill = (float)total*60;
    else bill = (float)total*70;
    save_to_file(array, tail+1, average, bill);

    free(array);
    return 0;
}

void save_to_file(int *array, int size, float average, float bill){
    printf("Saving data to file...\n");
    FILE *file = fopen("q3.txt", "w");
    if(file == NULL){
        printf("Error in opening the file\n");
        return;
    }

    fprintf(file, "----------- Electricity Bill Summary -----------\n");
    fprintf(file, " DAY  |  Units Consumed\n");
    for (int i = 0; i < size; i++){
        fprintf(file, " %3d  |  %d\n", i+1, array[i]);
    }
    fprintf(file, "-------------------------\n");
    fprintf(file, "Average Units Consumed: %.1f\n", average);
    fprintf(file, "Total Bill: %.1f\n", bill);

    printf("Data saved successfully to q3.txt\n");
    fclose(file);
}