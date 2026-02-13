#include <stdio.h>

int main(){
    int distance = 500,day = 1;
    while (distance<2000)
    {
        distance*=1.05;
        day++;
    }
    printf("The jogger ran %dm on day %d", distance, day);
    
    return 0;
}