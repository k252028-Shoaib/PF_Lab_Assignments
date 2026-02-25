#include <stdio.h>

void calc_avg_and_category(float data[][7], float average[], char *category[]);
void compact_report(float data[][7], float average[], char *category[]);
void detailed_report(float data[][7], float average[], char *category[]);

int main(){
    float data[5][7];
    float average[5] = {0.0};
    char *category[5]; //E = Efiicient, M = Moderate, P = Poor
    int choice;
    void (*function_ptr)(float data[][7], float average[], char *category[]);

    //inputting data
    for(int i = 0; i<5; i++){
        for(int j = 0; j<7; j++){
            printf("Enter mileage (km/l) for vehicle %d on day %d: ", i+1, j+1);
            scanf(" %f", &data[i][j]);
        }
    }

    calc_avg_and_category(data,average,category);

    printf("Enter 1 if you want a compact report, 2 if detailed report: ");
    scanf(" %d", &choice);
    if (choice == 1) function_ptr = &compact_report;
    else if (choice == 2) function_ptr = &detailed_report;

    function_ptr(data, average, category);
    return 0;
}

void calc_avg_and_category(float data[][7], float average[], char *category[]){
    for(int i = 0; i<5; i++){
        float sum = 0.0;

        for(int j = 0; j<7; j++){
            sum += data[i][j];
        }

        average[i] = sum/7;

        if (average[i] >= 18) category[i] = "Efficient";
        else if (average[i] >= 12) category[i] = "Moderate";
        else category[i] = "Poor";
    }
}

void compact_report(float data[][7], float average[], char *category[]){
    printf("------------ Compact Report ------------\n");
    for(int i = 0; i<5; i++){
        printf("Vehicle: %d, Category: %s, Average: %.2f\n", i+1, category[i], average[i]);
    }
    printf("----------------------------------------\n");
}

void detailed_report(float data[][7], float average[], char *category[]){
    printf("-------------------- Detailed Report --------------------\n");

    printf("Fuel Consumption Table:\n");
    printf("      | Day 1 | Day 2 | Day 3 | Day 4 | Day 5 | Day 6 | Day 7 |");
    for(int i = 0; i<5; i++){
        printf("\nCar %d ", i+1);
        for(int j = 0; j<7; j++){
            printf("  %4.1f  ", data[i][j]);
        }
    }
    printf("\n--------------------------------------------------------\n");
    printf("Vehicles' Average:\n");
    for(int i = 0; i<5; i++){
        printf("Vehicle: %d, Category: %s, Average: %.2f\n", i+1, category[i], average[i]);
    }

    printf("--------------------------------------------------------\n");
    int highest = 0;
    for(int i = 0; i<5; i++){
        if(average[highest] < average[i]) highest = i;
    }
    printf("The Vehicle %d has the highest average which is %.1f\n", highest+1, average[highest]);
    printf("--------------------------------------------------------\n");
}