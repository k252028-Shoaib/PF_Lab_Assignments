#include <stdio.h>

int main(){
    int rating, driver_distance;
    printf("Enter the rating of the driver (1-5) : ");
    scanf("%d", &rating);
    printf("Enter the driver distance from passenger (in km): ");
    scanf("%d", &driver_distance);

    if (rating>=4 && driver_distance<=5) printf("Top driver nearby");
    else if (rating>=3 && driver_distance <=10) printf("Average driver assigned");
    else printf("No suitable driver available");
    return 0;
}