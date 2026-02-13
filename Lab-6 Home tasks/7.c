#include <stdio.h>

int main(){
    int base = 0, exponent = 0, answer=1;

    printf("Enter the base: ");
    scanf(" %d", &base);
    printf("Enter the exponent: ");
    scanf(" %d", &exponent);

    for (exponent; exponent>0; exponent--)
    {
        answer *= base;
    }

    printf("Answer: %d", answer);
    
    return 0;
}