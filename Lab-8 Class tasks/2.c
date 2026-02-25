#include <stdio.h>

int main(){
    int array[4][6],count[4], total = 0, highest = 0;

    //initialising the array
    for (int i = 0; i<4; i++){
        for (int j = 0 ; j<6; j++){
            printf("Enter 1 if room %d in ward %d is occupied, else enter 0: ", j+1, i+1);
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
    //finding highest (== maximum)
    for (int i = 0; i<4; i++){
        if (count[highest]<count[i]) highest = i; 
    }
    printf("The ward with maximum/highest occupancy is %d\n", highest+1);
    printf("Total number of occupied beds is %d and number of vacant beds is %d\n",total,24-total);
    if (total<=14) printf("Increase Admission Drive"); //<=14 is because 60% of 24 is 14.4, so less than 14.4 is <=14 for integers
    return 0;
}