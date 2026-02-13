#include <stdio.h>

int main(){
    int student_id, reversed = 0;

    printf("Enter the last four digits of your student id: ");
    scanf(" %d", &student_id);
    
    for (int i = 1000; i>=1; i/=10){
        reversed += (student_id%10)*i;
        student_id /= 10;
    }

    printf("The sum is: %d", reversed);

    return 0;
}