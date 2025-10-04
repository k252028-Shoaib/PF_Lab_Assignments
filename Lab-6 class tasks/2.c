#include <stdio.h>

int main(){
    int day = 1;
    for (int savings = 0; savings<100; day++){
        savings = savings + day;
    }
    printf("Total savings reached or exceeded $100 at day %d", day);
    return 0;
}

