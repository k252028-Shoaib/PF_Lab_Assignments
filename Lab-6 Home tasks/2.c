#include <stdio.h>

int main(){
    int town_a = 10000, town_b = 8000, year = 0;
    while (town_a>town_b)
    {
        year++;
        town_a+=250;
        town_b+=400;
    }
    printf("Town B surpasses Town A in population in the year %d \nTown B had population of: %d \nTown A  had population of: %d", year, town_b, town_a);
    return 0;
}