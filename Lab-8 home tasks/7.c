#include <stdio.h>

int main(){
    int data[3][3], key[3][3], encrypted[3][3];
    int highest_i = 0, highest_j = 0;

    // initialising the arrays
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Enter value for data matrix at %dx%d: ", i + 1, j + 1);
            scanf(" %d", &data[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Enter value for key matrix at %dx%d: ", i + 1, j + 1);
            scanf(" %d", &key[i][j]);
        }
    }

    // encrypting the data and finding highest
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            encrypted[i][j] = (data[i][j] * key[i][j]) + (i + j);
            if (encrypted[highest_i][highest_j] < encrypted[i][j]){
                highest_i = i;
                highest_j = j;
            }
        }
    }

    // displaying the encrypted array
    printf("\nEncrypted Matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", encrypted[i][j]);
        }
        printf("\n");
    }

    // output
    printf("\nThe cell with the highest value is (%d, %d) with a value of %d\n", highest_i + 1, highest_j + 1, encrypted[highest_i][highest_j]);
    
    return 0;
}