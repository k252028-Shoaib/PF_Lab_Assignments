#include <stdio.h>

int main (){
    int i, total_fine=0, arr_status[15], arr_delay[15];

    //initialising the array
    for (i = 0; i<15; i++){
    	printf("Enter %dth students's fee payment status: ", i+1);
        scanf(" %d", &arr_status[i]);
        if (arr_status[i] == 0){
            printf("Enter %dth student's fee payment delay (in months): ", i+1);
            scanf(" %d", &arr_delay[i]);
        }
    }

    //Calculation etc
    for (i = 0; i<15; i++){
        printf("Student %d:", i+1);
        if (arr_status[i]==0){
            printf(" status == 0,");
            if (arr_delay[i]==1) {
                total_fine += 500;
                printf(" fine == 500, ");
            }
            else if (arr_delay[i]>1){
                total_fine += 1000;
                printf(" fine == 1000,");
            }
            else printf(" fine == 0,   ");
            printf(" remark == Defaulter\n");
        }
        else{
            printf(" status == 1, fine == 0,    remark == Cleared\n");
        }
    }
    printf("The total fine is %d", total_fine);

    return 0;
}