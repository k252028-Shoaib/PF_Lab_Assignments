#include <stdio.h>

//function to find the highest reading for each patient
void highest_f(float (*rows)[4], float *highest);

//function to find if a patint has temp above 101
void above_101_f(float *highest, int *above_101);

int main(){
    int above_101[5] = {0};
    float highest[5] = {0};
    float record[5][4]; //row = patient and column = reading

    //inputting the readings
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            printf("Enter the reading %d for patient %d ", j+1, i+1);
            scanf(" %f", &record[i][j]);
        }
    }

    highest_f(record, highest);
    for(int i = 0; i < 5; i++){
        printf("The highest temp for patient %d is %.1f\n", i+1, highest[i]);
    }

    above_101_f(highest, above_101);
    for (int i = 0; i < 5; i++){
        if (above_101[i] == 1) printf("Patient %d has tempertaure above 101!\n", i+1);
    }
    return 0;
}

void highest_f(float (*rows)[4], float *highest){
    //row = patient & col = reading
    for (int i = 0; i < 5; i++){
        float *col = *rows;
        float max = *col; //assuming that the first element in the row is the highest

        for (int j = 1; j < 4; j++){
            col++;
            if (*col > max) max = *col;
        }

        *highest = max;
        highest++;
        rows++;
    }
}

void above_101_f(float *highest, int *above_101){
    for (int i = 0; i < 5; i++){
        if (*highest > 101.0) *above_101 = 1;
        highest++;
        above_101++;
    }
}