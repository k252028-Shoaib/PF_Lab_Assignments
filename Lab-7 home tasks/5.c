#include <stdio.h>

int main (){
    int array[6], total_invigilator = 0, total_students = 0, i;

    //initialising the array
    for (i = 0; i<6; i++){
    	printf("Enter %dth section's number of students: ", i+1);
        scanf(" %d", &array[i]);
    }

    //Calculation etc
    for (i = 0; i<6; i++){
        total_students += array[i];
        if (array[i]<=30){
            printf("Section %d is assiegned 1 invigilator\n", i+1);
            total_invigilator += 1;
        }
        else if (array[i]<=60){
            printf("Section %d is assiegned 2 invigilators\n", i+1);
            total_invigilator += 2;
        }
        else {
            printf("Section %d is assiegned 3 invigilators\n", i+1);
            total_invigilator += 3;
        }
    }
    printf("Total invigilators needed are %d\n", total_invigilator);
    if (total_students> 300) printf("A cheif invigilator is also assigned");
    return 0;
}