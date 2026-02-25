#include <stdio.h>
/* assumptions: 
    1. marks are in decimals (integer)
    2. average is the average of all 3 subjects per student. Not average of all 5 students per subject
    3. topper is topper overall in all subjects combined
*/

//calculating average
void average_f(float record[][3], float average[]);
void grade_f(float average[], char grade[]);
int return_topper(float average[]);

int main(){
    float record[5][3]; // row = student, column = subject
    float average[5];
    char grade[5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            printf("Enter marks for student %d in subject %d: ", i+1, j+1);
            scanf(" %f", &record[i][j]);
        }
    }
    printf("\n");

    average_f(record, average);
    printf("\n");

    grade_f(average, grade);
    printf("\n");

    printf("Topper's index is %d\n", return_topper(average));
    return 0;
}

void average_f(float record[][3], float average[]){
    float sum = 0.0;
    for (int i = 0; i < 5; i++){
        float *ptr = *(record + i);   
        sum = 0.0;
        for (int j = 0; j < 3; j++){
            sum += *(ptr + j);        
        }
        *(average + i) = sum / 3.0;   
        printf("The average of student %d is %.2f\n", i+1, *(average + i));
    }
}

void grade_f(float average[], char grade[]){
    float *ptr = average;
    char *gptr = grade;
    for (int i = 0; i < 5; i++){
        if (*ptr > 90) *gptr = 'A';
        else if (*ptr > 80) *gptr = 'B';
        else if (*ptr > 70) *gptr = 'C';
        else if (*ptr > 60) *gptr = 'D';
        else *gptr = 'F';

        printf("The grade for student %d is %c\n", i+1, *gptr);
        ptr++;
        gptr++;
    }
}

int return_topper(float average[]){
    int topper = 0;
    float *ptr = average;
    for (int i = 1; i < 5; i++){
        if (*(ptr + topper) < *(ptr + i)) topper = i;
    }
    return topper;
}
