#include <stdio.h>

int main(){
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Pattern 1:\n");
    for (int i = 1; i<=rows; i++){
        for (int j = 1; j<=i; j++){
            printf("%d",j);
        }
        printf("\n");
    }
    for (int i = rows; i>0; i--){
        for (int j = 1; j<=i; j++){
            printf("%d",j);
        }
        printf("\n");
    }

    printf("\nPattern 2:\n");
    for (int i = 1; i<=rows; i++){
        for (int j = 1; j<=i; j++){
            printf("%d",i*j);
        }
        printf("\n");
    }
    for (int i = rows; i>0; i--){
        for (int j = 1; j<=i; j++){
            printf("%d",i*j);
        }
        printf("\n");
    }
    return 0;
}