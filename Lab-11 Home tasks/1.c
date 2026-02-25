#include <stdio.h>

typedef struct Building {
    int ID;
    float initialHeight;
    float growthRate;
}Building;

void compute_height(Building *b, int n){
    if(n == 0) return;
    
    compute_height(b, n-1); //recursive call to get previous state
    
    // H(n) = H(n-1) + floor(H(n-1) * growthRate)
    float growth = b->initialHeight * b->growthRate;
    b->initialHeight += growth;
}

int main(){
    Building b;
    int days;

    printf("Enter Building ID: ");
    scanf(" %d", &b.ID);
    printf("Enter Initial Height: ");
    scanf(" %f", &b.initialHeight);
    printf("Enter Growth Rate (decimal, e.g. 0.05): ");
    scanf(" %f", &b.growthRate);
    printf("Enter number of days to simulate: ");
    scanf(" %d", &days);

    compute_height(&b, days);

    printf("Final Height after %d days: %.2f\n", days, b.initialHeight);

    return 0;
}