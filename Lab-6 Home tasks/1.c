#include <stdio.h>

int main(){
    float investment = 1000.0;
    int years = 1;
    while (years<=10)
    {
        printf("The total at the end of year %d is %.1f\n", years, investment);
        investment *= 1.05;
        years++;
    }
    

    return 0;
}