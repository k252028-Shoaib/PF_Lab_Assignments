#include <stdio.h>

int main(){
    int NoAttempts = 0;

    printf("Please enter the number of failed attempts: ");
    scanf("%d", &NoAttempts);

    if (NoAttempts == 0){
        printf("No suspicious activity");
    }
    else if(NoAttempts > 0 && NoAttempts <= 3){
        printf("Warning: User may have forgotten password");
    }
    else if(NoAttempts >= 4 && NoAttempts <= 6){
        printf("Alert: Possible unauthorized access attempt");
    }
    else{
        printf("Critical: Account Locked due to brute-force attempts");
    }

    return 0;
}
