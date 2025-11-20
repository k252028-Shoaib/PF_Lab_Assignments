#include <stdio.h>
#include <string.h>

int main(){
    char pass[100];
    int len;
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    char *specials = "!@#$%^&*()-_+=<>?;:,.[]{}|\\/`~\"'";

    printf("Enter password: ");
    scanf(" %99[^\n]", pass);

    len = strlen(pass);

    for (int i = 0; i < len; i++){
        if (pass[i] >= 'a' && pass[i] <= 'z') hasLower = 1;
        else if (pass[i] >= 'A' && pass[i] <= 'Z') hasUpper = 1;
        else if (pass[i] >= '0' && pass[i] <= '9') hasDigit = 1;
        else if (strchr(specials, pass[i]) != NULL) hasSpecial = 1;
    }

    if (len < 6) {
        printf("Weak\n");
    } else if (len >= 8 && hasLower && hasUpper && hasDigit && hasSpecial) {
        printf("Strong\n");
    } else {
        printf("Medium\n");
    }

    return 0;
}
