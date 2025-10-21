#include <stdio.h>

int main(){
    int array[10][4], count = 0, count2 = 0, x, y;
    
    //initialising the array
    for (int i = 0; i<10; i++){
        for (int j = 0; j<4; j++){
            printf("Enter 0 if seat %dx%d is not reserved, else enter 1: ",i+1,j+1);
            scanf(" %d", &array[i][j]);
        }
    }
    
    //display seat map
    printf("\n--- Current Seat Map ---\n");
    printf("       ");
    for (int i = 1; i<=4;i++){
        printf(" Seat %2d |",i);
    }
    for (int i = 0; i<10; i++){
        printf("\nRow %d: ",i+1);
        for (int j = 0; j<4; j++){
            printf("%5d    ",array[i][j]);
            // Removed the count++ from here
        }
    }
    printf("\n\n");

    //finding full rows
    for (int i = 0; i<10; i++){
        count = 0; // Reset count for each new row
        for (int j = 0; j<4; j++){
            if (array[i][j] == 1) count++;
        }
        if (count == 4) count2++;
    }
    printf("There are %d full rows\n", count2);

    //inputting seat number
    printf("According to the given seat map, please give your seat number by first telling the row number then seat number: ");
    scanf(" %d", &x);//row
    scanf(" %d", &y);//seat

    // Check if seat is taken *before* booking
    if(array[x-1][y-1] == 1) {
        printf("Sorry, that seat (%dx%d) is already reserved.\n", x, y);
    } else {
        array[x-1][y-1] = 1;
        printf("Thank you! Seat %dx%d is now reserved for you.\n", x, y);
    }
    
    //display UPDATED seat map
    printf("\n--- Updated Seat Map ---\n");
    printf("       ");
    for (int i = 1; i<=4;i++){
        printf(" Seat %2d |",i);
    }
    for (int i = 0; i<10; i++){
        printf("\nRow %d: ",i+1);
        for (int j = 0; j<4; j++){
            printf("%5d    ",array[i][j]);
        }
    }
    printf("\n");

    return 0;
}