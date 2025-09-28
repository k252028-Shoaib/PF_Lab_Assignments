#include <stdio.h>

int main(){
    int StudentID = 0;
    int registered = 2023;

    printf("Please enter your student id: ");
    scanf("%d", &StudentID);

    if (StudentID == registered){
        printf("Valid User: Proceed to login");
    }
    else{
        printf("Unknown User: Access Denied");
    }

    return 0;
}
