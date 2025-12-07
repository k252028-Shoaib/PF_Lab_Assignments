#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine{
    char medicineName[50];
    int quantityAvailable;
    float unitPrice;
} Medicine;

void save_to_file(Medicine *array, int size);

int main(){
    Medicine *array = (Medicine*) malloc(sizeof(Medicine)*1);
    int tail = 0;
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Adding medication to inventory.....\n");
        printf("Enter Medicine Name: ");
        scanf(" %[^\n]", (array+tail)->medicineName);
        printf("Enter Quantity: ");
        scanf(" %d", &(array+tail)->quantityAvailable);
        printf("Enter Unit Price: ");
        scanf(" %f", &(array+tail)->unitPrice);

        printf("Do you want to add another medicine? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if(choice){
            tail++;
            Medicine *temp = realloc(array, sizeof(Medicine)*(tail+1));
            if(temp == NULL){
                printf("Memory re-allocation failed\n");
                free(array);
                return 1;
            }
            array = temp;
        }
    } while (choice);

    save_to_file(array, tail+1);
    free(array);
    return 0;
}

void save_to_file(Medicine *array, int size){
    printf("Saving data to file...\n");
    FILE *fp = fopen("medicine_inventory.txt", "w");
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    float total_value = 0;
    fprintf(fp, "----------- Inventory Report -----------\n");
    for(int i=0; i<size; i++){
        total_value += ((array+i)->quantityAvailable * (array+i)->unitPrice);
        fprintf(fp, "Name: %s | Qty: %d | Price: %.2f\n", (array+i)->medicineName, (array+i)->quantityAvailable, (array+i)->unitPrice);
        
        if((array+i)->quantityAvailable < 5){
            fprintf(fp, ">>> LOW STOCK ALERT <<<\n");
        }
    }
    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "Total Inventory Value: %.2f\n", total_value);

    printf("Data saved successfully to medicine_inventory.txt\n");
    fclose(fp);
}