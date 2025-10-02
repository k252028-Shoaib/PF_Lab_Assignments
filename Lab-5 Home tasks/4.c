#include <stdio.h>

int main(){
    int distance, ride_type;
    float total_fare;
    printf("Enter distance: ");
    scanf("%d", &distance);
    printf("Enter ride type: 1 = Economy, 2 = Business, 3 = Luxury: ");
    scanf("%d", &ride_type);

    if (ride_type == 1) total_fare = 50*surge_multiplier*distance;
    else if (ride_type == 2) total_fare = 100*surge_multiplier*distance;
    else if (ride_type == 3) total_fare = 200*surge_multiplier*distance;

    printf("Total fare is %.2f", total_fare);

    return 0;
}



