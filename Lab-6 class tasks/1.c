#include <stdio.h>

int main(){
    int year = 1;
    for (int value = 30000; value>=15000; value=value*0.9){
        printf("The value is %d in the year %d\n", value, year);
        year++;
    }
    printf("It took %d years for the value to go below $15k", year);
    return 0;
}
