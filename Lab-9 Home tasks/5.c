#include <stdio.h>

void calculate(int (*array)[5]);

int main(){
    int attendance[30][5];

    //inputting attedance for each student:
    for (int i = 0; i < 30; i++){
        for (int j = 0; j<5; j++){
            printf("Enter attendance for student %d for day %d: ", i+1, j+1);
            scanf(" %d", &attendance[i][j]);
        }
    }
    
    calculate(attendance);
    return 0;
}

void calculate(int (*array)[5]){
    int count = 0; //counter for number of defaulters

    for (int i = 0; i < 30; i++){
        int sum = 0;
        for (int j = 0; j < 5; j++){
            sum += *(*(array + i) + j);
        }
        float percentage = ((float) sum/5) * 100;

        if (percentage < 75) count++;
        if (percentage > 90) printf("Student %d has Good attendance\n", i+1);
        else if (percentage > 75) printf("Student %d has Average attendance\n", i+1);
        else printf("Student %d has Poor attendance\n", i+1);
    }

    printf("\nTotal number of defaulters (<75%% attendance): %d\n", count);
}