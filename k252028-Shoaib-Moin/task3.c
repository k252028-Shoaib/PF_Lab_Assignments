#include <stdio.h>

int main() {
    float distance_travelled, fuel_used, price_per_liter;
    float efficiency, total = 0.0f;

    // Input data
    printf("Enter distance travelled (km): ");
    scanf("%f", &distance_travelled);

    printf("Enter fuel used (liters): ");
    scanf("%f", &fuel_used);

    printf("Enter price per liter: ");
    scanf("%f", &price_per_liter);

    // Calculate car's efficiency and total price
    efficiency = distance_travelled / fuel_used;
    total = price_per_liter * fuel_used;

    // Output
    printf("---------------------------\n     Fuel Report     \n---------------------------\n");
    printf("Distance   : %.2f km\n", distance_travelled);
    printf("Fuel used  : %.2f L\n", fuel_used);
    printf("Efficiency : %.2f km/L\n", efficiency);
    printf("Total      : %.2f PKR\n", total);
    printf("---------------------------\n");

    return 0;
}
