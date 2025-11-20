#include <stdio.h>
#include <string.h>
typedef struct {
    char id[20];
    int dist;
    float price;
    int type;
    float finalCost;
} Route;


float extraCost(int type) {
    if (type == 1) return 0;
    if (type == 2) return 50;
return 100;
}


float routeCost(int d, float p, int t) {
    if (d <= 0)
    return 0;

    int take = (d >= 10) ? 10 : d;
    float cost = take * p + extraCost(t);

    return cost + routeCost(d - take, p, t);
}


int main() {
    Route r;

    printf("Enter route ID: ");
    scanf("%s", r.id);
    printf("Enter distance: ");
    scanf("%d", &r.dist);
    printf("Enter base price: ");
    scanf("%f", &r.price);
    printf("Enter road type (1/2/3): ");
    scanf("%d", &r.type);

    r.finalCost = routeCost(r.dist, r.price, r.type);
    printf("Total Cost = %.2f", r.finalCost);
    return 0;
}
