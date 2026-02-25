#include <stdio.h>

typedef struct WeatherData{
    char city_name[50];
    float base_temp;
    float cooling_factor;
}WeatherData;

void recursive(int days, WeatherData *data);

int main(){
    WeatherData data;
    printf("Enter city name: ");
    scanf(" %[^\n]", data.city_name);
    printf("Enter base temp: ");
    scanf(" %f", &data.base_temp);
    printf("Enter the cooling factor: ");
    scanf(" %f", &data.cooling_factor);

    int days;
    printf("Enter the number of days to simulate: ");
    scanf(" %d", &days);

    recursive(days, &data);
    return 0;
}

void recursive(int days, WeatherData *data){
    if (days == 0){
        return;
    }
    recursive(days-1, data);
    
    float random_variation;
    printf("Is there a random variation on day %d?: (Enter 0 if no, else enter the value): ", days);
    scanf(" %f", &random_variation);
    data->base_temp += random_variation-data->cooling_factor;
    printf("Day %d: %.1f\n", days, data->base_temp);
}