#include <stdio.h>

int main(){
    int array[4][6],count[4], total = 0;

    //initialising the array
    for (int i = 0; i<4; i++){
        for (int j = 0 ; j<6; j++){
            printf("Enter 1 if room %d in ward %d is occupied, else enter 0", j+1, i+1);
            scanf(" %d", &array[i][j]);
        }
        count[i] = 0;
    }
    //Counting
    for (int i = 0; i<4; i++){
        for (int j = 0 ; j<6; j++){
            if(array[i][j]==1) {
                count[i]+=1;
                total++;
            }
        }
    }
    //finding highest
    for (int i = 0; i<4; i++){
        if(count[i] == 6) printf("The ward with maximum occupancy is %d", i+1);
        if (total<=14) printf("Increase Admission Drive"); //<=14 is because 60% of 24 is 14.4, so less than 14.4 is <=14 for integers
    }
    
    return 0;
}