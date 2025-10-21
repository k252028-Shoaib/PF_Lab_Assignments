#include <stdio.h>

int main(){
    int original[5][5], sharpened[5][5], sum1 = 0, sum2 = 0;

    //initialising the orginal array
    for (int i = 0; i < 5 ; i++){
        for(int j = 0; j<5 ; j++){
            printf("Enter value at %dx%d: ",i+1,j+1);
            scanf(" %d", &original[i][j]);
            sum1 += original[i][j];
        }
    }

    //sharpened array calculation
    for (int i = 0; i<5 ; i++){
        for (int j = 0; j<5 ; j++){
            sharpened[i][j] = original[i][j]*2;
            if (sharpened[i][j]>255) sharpened[i][j] = 255;
            sum2 += sharpened[i][j];
        }
    }

    //Displaying sharpened array
    for (int i = 0; i<5 ; i++){
        for (int j = 0; j<5 ; j++){
            printf("%3d ",sharpened[i][j]);
        }
        printf("\n");
    }

    //Calculating averagess
    printf("Average pixel density before was %.2f and after sharpening it is %.2f", (float)sum1/25, (float)sum2/25);
    return 0;
}