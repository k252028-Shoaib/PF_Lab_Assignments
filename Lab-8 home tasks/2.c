#include <stdio.h>
int main() {
    int array[3][3], flag = 1;

    // initializing the array
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Enter value for suduko box %dx%d: ", i + 1, j + 1);
            scanf(" %d", &array[i][j]);
        }
    }

    // Checks
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (array[i][j] < 1 || array[i][j] > 9){
                printf("Invalid grid\n");
                flag = 0;
                return 0; // finish execution since it's invalid
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                for (int l = 0; l < 3; l++){
                    if (i == k && j == l)
                        continue;
                    else if (array[i][j] == array[k][l]){
                        printf("Invalid grid\n");
                        flag = 0;
                        return 0; // finish execution since it's invalid
                    }
                }
            }
        }
    }
    if (flag == 1)
        printf("Valid grid");
    return 0;
}