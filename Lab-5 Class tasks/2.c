#include <stdio.h>

int main(){
    int type, action;
    printf("Enter the type of attack(type: 1 = Fake Login Page, 2 = Malicious Link, 3 = Urgent Money Request)");
    scanf("%d", &type);

    switch (type){
        case 1:
            printf("Enter the user action(action: 1 = Clicked, 2 = Reported, 3 = Ignored)");
            scanf(" %d", &action);
            switch (action){
            case 1:
                printf("Fake Login Page\nSeverity = High Risk");
                break;
            case 2:
                printf("Fake Login Page\nSeverity = Low Risk");
                break;
            case 3:
                printf("Fake Login Page\nSeverity = Medium Risk");
                break;
            default:
                printf("invalid input");
            }
            break;
        case 2:
            printf("Enter the user action(action: 1 = Clicked, 2 = Reported, 3 = Ignored)");
            scanf(" %d", &action);
            switch (action){
            case 1:
                printf("Malicious Link\nSeverity = High Risk");
                break;
            case 2:
                printf("Malicious Link\nSeverity = low Risk");
                break;
            case 3:
                printf("Malicious Link\nSeverity = Medium Risk");
                break;
            default:
                printf("invalid input");
            }
            break;
        case 3:
            printf("Enter the user action(action: 1 = Clicked, 2 = Reported, 3 = Ignored)");
            scanf(" %d", &action);
            switch (action){
            case 1:
                printf("Urgent Money Request\nSeverity = High Risk");
                break;
            case 2:
                printf("Urgent Money Request\nSeverity = Medium Risk");
                break;
            case 3:
                printf("Urgent Money Request\nSeverity = low Risk");
                break;
            default:
                printf("invalid input");
            }
            break;
        default:
            printf("inavlid input");
        }
    return 0;
}



