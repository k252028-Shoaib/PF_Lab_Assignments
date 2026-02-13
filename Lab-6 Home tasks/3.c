#include <stdio.h>

int main(){
    int count = 0, last, second, i=1;

    printf("Enter the second last digit of your student id: ");
    scanf(" %d", &second);
    printf("Enter the last digit of your student id: ");
    scanf(" %d", &last);

    while (count<10)
    {
        if (i%last == 0 && i%second == 0){
            count++;
            printf("%d\n", i);
    }
        i++;
    }
    
    return 0;
}