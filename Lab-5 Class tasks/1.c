#include <stdio.h>

int main(){
    int noa = 0, interval = 0;
    printf("Enter the number of attempts: ");
    scanf(" %d", &noa);
    printf("Enter the time interval: ");
    scanf(" %d", &interval);

    if (noa>5 && interval<=10) printf("Brute force attack");
    else if(noa >3 && interval<=30) printf("Suspicious Activity");
    else printf("Normal Login Behavior");
    return 0;
}