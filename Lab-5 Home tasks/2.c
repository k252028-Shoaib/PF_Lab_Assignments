#include <stdio.h>

int main(){
    int ride_type,base_fare;
    char distance;
    printf("Enter ride type: 1 = Economy, 2 = Business, 3 = Luxury: ");
    scanf("%d", &ride_type);
    switch (ride_type){
    case 1:
        printf("Enter distance (s for short/l for long): ");
        scanf(" %c", &distance);
        if (distance == 's') base_fare = 100;
        else base_fare = 300;
        printf("Economy base fare is: %d", base_fare);
        break;
    case 2:
        printf("Enter distance (s for short/l for long): ");
        scanf(" %c", &distance);
        if (distance == 's') base_fare = 100;
        else base_fare = 300;
        printf("Business base fare is: %d", base_fare);
        break;
    case 3:
        printf("Enter distance (s for short/l for long): ");
        scanf(" %c", &distance);
        if (distance == 's') base_fare = 100;
        else base_fare = 300;
        printf("Luxury base fare is: %d", base_fare);
        break;
    default:
        printf("Invalid input");
    }
    return 0;
}


