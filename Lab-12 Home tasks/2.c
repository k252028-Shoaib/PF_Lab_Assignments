#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Student{
    char studentName[50];
    char rollNumber[20];
    int seatNumber;
} Student;

int check_alphanumeric(char *str, int index);
void save_to_file(Student *array, int size);

int main(){
    Student *array = (Student*) malloc(sizeof(Student)*1); //starting with 1 element
    int tail = 0; //tells the index of the last element
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do
    {
        printf("Assigning seat.....\n");
        printf("Enter Student Name: ");
        scanf(" %[^\n]", (array+tail)->studentName);
        
        int valid = 0;
        do {
            printf("Enter Roll Number (Alphanumeric): ");
            scanf(" %[^\n]", (array+tail)->rollNumber);
            if(check_alphanumeric((array+tail)->rollNumber, 0)){
                valid = 1;
            } else {
                printf("Invalid Roll Number. Try again.\n");
            }
        } while (!valid);

        printf("Enter Seat Number: ");
        scanf(" %d", &(array+tail)->seatNumber);

        printf("Do you want to add another student? (1 for yes, 0 for no): ");
        scanf(" %d", &choice);

        if(choice){
            tail++;
            Student *temp = realloc(array, sizeof(Student)*(tail+1));
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

int check_alphanumeric(char *str, int index){
    if (*(str+index) == '\0') return 1;
    if (!isalnum(*(str+index))) return 0;
    return check_alphanumeric(str, index+1);
}

void save_to_file(Student *array, int size){
    printf("Saving data to file...\n");
    FILE *fp = fopen("seating.txt", "w");
    if(fp == NULL){
        printf("Error opening the file\n");
        return;
    }

    fprintf(fp, "----------- Exam Seating Plan -----------\n");
    for(int i=0; i<size; i++){
        fprintf(fp, "Seat: %d | Name: %s | Roll No: %s\n", (array+i)->seatNumber, (array+i)->studentName, (array+i)->rollNumber);
    }
    printf("Data saved successfully to seating.txt\n");
    fclose(fp);
}