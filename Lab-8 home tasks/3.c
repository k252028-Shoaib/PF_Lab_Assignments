#include <stdio.h>

int main(){
    int array[4][5], salesman[4], product[5], highest_s = 0, highest_p = 0;

    // initializing the arrays
    for(int j = 0; j < 5; j++) {
        product[j] = 0;
    }
    for(int i = 0; i < 4; i++) {
        salesman[i] = 0;
    }
    for (int i = 0; i < 4; i++){   
        for (int j = 0; j < 5; j++){
            printf("Enter sales value for salesmen %d and product %d: ", i + 1, j + 1);
            scanf(" %d", &array[i][j]);
        }
    }
    //computing total sales value for each salesman and each product
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            salesman[i] += array[i][j];
            if (array[highest_s][highest_p]<array[i][j]){
                highest_s = i;
                highest_p = j;
            }
        }
        
        if (salesman[i]>10000) printf("Salesman %d got a 10%% bonus\n", i+1);
    }
    printf("Salesman %d sold the most expensive product\n", highest_s+1);
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 4; i++){
            product[j] += array[i][j];
        }
    }
    return 0;
}