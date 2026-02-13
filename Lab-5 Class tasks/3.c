#include <stdio.h>
#include <math.h>

int main(){
    int vulnerability = 0,malware = 0, risk = 0;
    printf("Enter vulnerability score (1-10): ");
    scanf("%d", &vulnerability);
    printf("Enter malware strength score (1-10): ");
    scanf("%d", &malware);

    risk = pow(vulnerability,2)+pow(malware,2)/20;
    (risk>5) ? printf("High Infection Probability") : printf("Low Infection Probability");

    return 0;
}