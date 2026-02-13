#include <stdio.h>

int main(){
    int student_id, sum = 0;

    printf("Enter the last four digits of your student id: ");
    scanf(" %d", &student_id);
    
    for (int i = 1; i<=4; i++){
        sum += (student_id%10);
        student_id /= 10;
    }

    printf("The sum is: %d", sum);

    return 0;
}