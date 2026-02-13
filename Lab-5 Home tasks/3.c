#include <stdio.h>
#include <math.h>

int main(){
    int no_of_rides;
    float surge_multiplier;
    printf("Enter the number of rides requested: ");
    scanf(" %d", &no_of_rides);
    surge_multiplier = sqrt(no_of_rides)/2;
    if (surge_multiplier > 3) surge_multiplier = 3;
    printf("final surge multiplier is: %.2f", surge_multiplier);
    return 0;
}
