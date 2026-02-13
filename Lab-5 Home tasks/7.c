#include <stdio.h>
#include <math.h>

int main(){
    //initialisation
    int age = 0, balance = 0;
    int ride_type,base_fare;
    char dis;
    int no_of_rides;
    float surge_multiplier;
    int distance;
    float total_fare;
    int points = 0;
    float discount;
    int rating, driver_distance;

    //eligibility
    printf("Enter you age: ");
    scanf("%d", &age);
    printf("Enter your balance: ");
    scanf("%d", &balance);

    if (age<21) printf("Not eligible for ride (underage)");
    else if (balance<200) printf("Not eligible (insufficient balance)");
    else {
        //ride type
        printf("Enter ride type: 1 = Economy, 2 = Business, 3 = Luxury: ");
        scanf("%d", &ride_type);
        switch (ride_type){
        case 1:
            printf("Enter distance (s for short/l for long): ");
            scanf(" %c", &dis);
            if (dis == 's') base_fare = 100;
            else base_fare = 300;
            printf("Economy base fare is: %d\n", base_fare);
            break;
        case 2:
            printf("Enter distance (s for short/l for long): ");
            scanf(" %c", &dis);
            if (dis == 's') base_fare = 100;
            else base_fare = 300;
            printf("Business base fare is: %d\n", base_fare);
            break;
        case 3:
            printf("Enter distance (s for short/l for long): ");
            scanf(" %c", &dis);
            if (dis == 's') base_fare = 100;
            else base_fare = 300;
            printf("Luxury base fare is: %d\n", base_fare);
            break;
        default:
            printf("Invalid input\n");
        }

        //surge multiplier
        printf("Enter the number of rides requested: ");
        scanf(" %d", &no_of_rides);
        surge_multiplier = sqrt(no_of_rides)/2;
        if (surge_multiplier > 3) surge_multiplier = 3;
        printf("final surge multiplier is: %.2f\n", surge_multiplier);

        //total fare
        printf("Enter distance needed to travel: ");
        scanf("%d", &distance);

        if (ride_type == 1) total_fare = 50*surge_multiplier*distance;
        else if (ride_type == 2) total_fare = 100*surge_multiplier*distance;
        else if (ride_type == 3) total_fare = 200*surge_multiplier*distance;

        //loyalty points discount
        printf("Enter the amount of points you have: ");
        scanf("%d", &points);
        (points>1000)? printf("Your discount is %.1f%%\n", discount = 20) : printf("Your discount is %.1f%%\n", discount = 5);
        
        //final fare
        total_fare = base_fare+(total_fare*(1-discount/100.0));

        //driver assignment
        printf("Enter the rating of the driver (1-5) : ");
        scanf("%d", &rating);
        printf("Enter the driver distance from passenger (in km): ");
        scanf("%d", &driver_distance);

        

        //output
        printf("----------------\n   Ride Details   \n----------------\n");
        printf("Rider is eligible\n");
        if (rating>=4 && driver_distance<=5) printf("Top driver nearby is assigned\n");
        else if (rating>=3 && driver_distance <=10) printf("Average driver assigned\n");
        else printf("No suitable driver available\n");
        printf("Final fare is: %.2f\n", total_fare);
        printf("----------------\n");
        }
    return 0;
}