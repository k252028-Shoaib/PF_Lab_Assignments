#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BookLog{
    char bookTitle[50];
    int memberID;
    int checkoutTime; // assuming day number or 24h format
    int returnDueDays;
} BookLog;

void save_to_file(BookLog *array, int size);

int main(){
    BookLog *array = (BookLog*) malloc(sizeof(BookLog)*1);
    int tail = 0;
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Logging checkout.....\n");
        printf("Enter Book Title: ");
        scanf(" %[^\n]", (array+tail)->bookTitle);
        printf("Enter Member ID: ");
        scanf(" %d", &(array+tail)->memberID);
        printf("Enter Checkout Time (Day 1-365): ");
        scanf(" %d", &(array+tail)->checkoutTime);
        printf("Enter Return Due Days: ");
        scanf(" %d", &(array+tail)->returnDueDays);

        printf("Do you want to add another checkout? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if(choice){
            tail++;
            BookLog *temp = realloc(array, sizeof(BookLog)*(tail+1));
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

void save_to_file(BookLog *array, int size){
    printf("Saving data to file...\n");
    FILE *fp = fopen("library_log.csv", "w"); // CSV format
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(fp, "BookTitle,MemberID,CheckoutTime,DueDate\n");
    for(int i=0; i<size; i++){
        int due = (array+i)->checkoutTime + (array+i)->returnDueDays;
        fprintf(fp, "%s,%d,%d,%d\n", (array+i)->bookTitle, (array+i)->memberID, (array+i)->checkoutTime, due);
    }

    printf("Data saved successfully to library_log.csv\n");
    fclose(fp);
}