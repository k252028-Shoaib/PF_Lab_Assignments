#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bed{
    int is_occupied;
    char patient_name[50];
    int days_admitted;
    int ward_id;
}bed;

int recursion(bed *ptr, int size, int index);
void save_to_file(bed *ptr, int size);

int main (){
    bed *array = (bed*) malloc(sizeof(bed)*1); //starting with only 1 bed
    int tail = 0;//tells the index of the last element. ALso tells the size but by 1 less
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    //Entering all the data
    do
    {
        //getting data from the user  
        printf("Adding a bed.....\n");    
        (array+tail)->is_occupied = 0;
        strcpy((array+tail)->patient_name, "");
        (array+tail)->days_admitted = 0;
        printf("Enter ward id for the bed: ");
        scanf(" %d", &(array+tail)->ward_id);
 
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);
        if (choice){
            tail++;
            bed *temp = realloc(array, sizeof(bed)*(tail+1));//making a temp variable so if the allocation failed the old data isn't lost
            if(temp == NULL){
                printf("Memory re-allocation failed\n");
                free(array); //free the original array before exiting
                return 1;
            }
            array = temp;
        }
    } while (choice);
    printf("Total number of occupied beds: %d", recursion(array, tail+1, 0));
    save_to_file(array, tail+1);
    free(array);
    return 0;
}

int recursion(bed *ptr, int size, int index){
    int choice;
    static int total = 0;
    if (index == size){
        return total;
    }

    printf("Is a bed in ward %d occupied? (1 for yes and 0 for no): ", (ptr+index)->ward_id); //no specific bed is asked, just any bed in the ward
    scanf(" %d", &choice);
    if(choice){
        (ptr+index)->is_occupied = 1;
        printf("Enter patient name: ");
        scanf(" %[^\n]", (ptr+index)->patient_name);
        printf("Enter the number of days the patient is admitted for: ");
        scanf(" %d", &(ptr+index)->days_admitted);
        total++;
    }

    return recursion(ptr, size, index+1);
}

void save_to_file(bed *ptr, int size){
    printf("Saving data to file...\n");
    FILE *file = fopen("q2.txt", "w");
    if (file == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(file, "---------------------- Ward data ----------------------\n");
    for (int i = 0; i < size; i++){
        fprintf(file, "Patient Name: %s \nOccupied: %d \nDays admitted: %d \nWard id: %d\n", (ptr+i)->patient_name, (ptr+i)->is_occupied, (ptr+i)->days_admitted, (ptr+i)->ward_id);
        fprintf(file, "-----------------------------\n");
    }

    printf("Data saved successfully to q2.txt\n");
    fclose(file);
}