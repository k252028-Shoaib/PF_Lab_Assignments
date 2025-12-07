#include <stdio.h>
#include <stdlib.h>

int recursive_total(int *array, int size, int index);
void save_to_file(int *array, int size);

int main(){
    int *array = (int*) malloc(sizeof(int)*1); // stores headcount per gate
    int tail = 0;
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Enter headcount for Gate %d: ", tail+1);
        scanf(" %d", array+tail);

        printf("Do you want to add another gate? (1 for yes, 0 for no): ");
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

    printf("Total attendees: %d\n", recursive_total(array, tail+1, 0));
    save_to_file(array, tail+1);
    free(array);
    return 0;
}

int recursive_total(int *array, int size, int index){
    if(index == size) return 0;
    return *(array+index) + recursive_total(array, size, index+1);
}

void save_to_file(int *array, int size){
    printf("Saving data to file...\n");
    FILE *fp = fopen("attendance.txt", "w");
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    int highest = 0, gate_idx = 0;

    fprintf(fp, "----------- Attendance Log -----------\n");
    for(int i=0; i<size; i++){
        if(*(array+i) > highest){
            highest = *(array+i);
            gate_idx = i;
        }
        fprintf(fp, "Gate %d: %d\n", i+1, *(array+i));
    }
    fprintf(fp, "--------------------------------------\n");
    fprintf(fp, "Gate with highest attendance: Gate %d (%d)\n", gate_idx+1, highest);

    printf("Data saved successfully to attendance.txt\n");
    fclose(fp);
}
