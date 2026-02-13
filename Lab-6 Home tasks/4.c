#include <stdio.h>

int main(){
    int student_id = 0, sum = 1;

    printf("Please enter the sum of the last 2 digits of your student id: ");
    scanf(" %d", &student_id);

    for (int i = 1; i<=student_id; i++)
    {
        sum *= i;
    }


    printf("answer:  %d ", sum);
    
    return 0;
}