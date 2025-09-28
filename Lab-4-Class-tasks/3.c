#include <stdio.h>

int main(){
    int SevCode = 0;

    printf("Please enter the severity code (1-4): ");
    scanf("%d", &SevCode);

    switch(SevCode){
        case 1:
            printf("Low (Unusual login time)");
            break;
        case 2:
            printf("Medium (Suspicious failed attempts)");
            break;
        case 3:
            printf("High (Multiple accounts targeted)");
            break;
        case 4:
            printf("Critical (Brute-force/DDoS attack detected)");
            break;
        default:
            printf("Invalid Code: Enter a number between 1 and 4");
    }
    return 0;
}
