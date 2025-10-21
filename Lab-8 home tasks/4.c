#include <stdio.h>

int main(){
    float array[3][3][3], z_layer[3];
    int highest_z = 0, hottest_x = 0, hottest_y = 0, hottest_z = 0;

    //initialising the arrays
    for (int i = 0; i<3; i++){
        z_layer[i] = 0;
    }
    for (int x = 0; x<3; x++){
        for (int y = 0; y<3; y++){
            for (int z = 0; z<3; z++){
                printf("Enter temp at point %dx%dx%d", x+1, y+1, z+1);
                scanf(" %f", &array[x][y][z]);
            }
        }
    }

    //hottest z layer
    for (int z = 0; z<3; z++){
        for (int y = 0; y<3; y++){
            for (int x = 0; x<3; x++){
                z_layer[z] += array[x][y][z];
            }
        }
        z_layer[z] /= 9.0;
        if (z_layer[highest_z]<z_layer[z]) highest_z = z;
    }
    printf("Hottest layer is %d\n", highest_z+1);

    //hottest point
    for (int x = 0; x<3; x++){
        for (int y = 0; y<3; y++){
            for (int z = 0; z<3; z++){
                if(array[hottest_x][hottest_y][hottest_z] < array[x][y][z]){
                    hottest_x = x;
                    hottest_y = y;
                    hottest_z = z;
                }
            }
        }
    }
    printf("The point with the hottest temperature is (%d,%d,%d)", hottest_x+1, hottest_y+1, hottest_z+1);
    return 0;
}