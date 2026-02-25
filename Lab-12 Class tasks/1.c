#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order{
    char itemName[50];
    int quantity;
    float unitPrice;
    char customerName[50];
} Order;

void save_orders_to_file(Order *ptr, int size, float total_revenue);

int main (){
    Order *array = (Order*) malloc(sizeof(Order)*1); //starting with only 1 order slot
    int tail = 0; //tells the index of the last element
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    float total_revenue = 0;
    //Entering all the data
    do
    {
        //getting data from the user
        printf("Adding an order.....\n");
        
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", (array+tail)->customerName);
        printf("Enter Item Name: ");
        scanf(" %[^\n]", (array+tail)->itemName);
        printf("Enter Quantity: ");
        scanf(" %d", &(array+tail)->quantity);
        printf("Enter Unit Price: ");
        scanf(" %f", &(array+tail)->unitPrice);

        total_revenue += ((array+tail)->quantity * (array+tail)->unitPrice);

        printf("Do you want to add another order? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if (choice){
            tail++;
            Order *temp = realloc(array, sizeof(Order)*(tail+1)); //making a temp variable so if the allocation failed the old data isn't lost
            if(temp == NULL){
                printf("Memory re-allocation failed\n");
                free(array); //free the original array before exiting
                return 1;
            }
            array = temp;
        }
    } while (choice);
 
    printf("Total Revenue for the day: %.2f\n", total_revenue);
    save_orders_to_file(array, tail+1, total_revenue);
    //free all memory properly
    free(array);
    return 0;
}

void save_orders_to_file(Order *ptr, int size, float total_revenue){
    printf("Saving data to file...\n");
    FILE *file = fopen("q1.txt", "w");
    if (file == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(file, "---------------------- Daily Orders Receipt ----------------------\n");
    for (int i = 0; i < size; i++){
        float subtotal = (ptr+i)->quantity * (ptr+i)->unitPrice;
        fprintf(file, "Customer: %s \nItem: %s \nQuantity: %d \nUnit Price: %.2f \nSubtotal: %.2f\n", 
                (ptr+i)->customerName, (ptr+i)->itemName, (ptr+i)->quantity, (ptr+i)->unitPrice, subtotal);
        fprintf(file, "-----------------------------\n");
    }
    fprintf(file, "GRAND TOTAL REVENUE: %.2f\n", total_revenue);

    printf("Data saved successfully to q1.txt\n");
    fclose(file);
}