#include <stdio.h>
#include <string.h>

int main(){
    char email[30];
    char domain[30];
    printf("Enter your email : ");
    scanf("%s", email);

    char*ptr = strchr(email, '@');
    strcpy(domain, ptr+1);
    printf("The domain is %s\n", domain);
    return 0;
}