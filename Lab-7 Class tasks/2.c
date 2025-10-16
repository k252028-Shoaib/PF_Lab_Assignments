#include <stdio.h>

int main (){
    int array[12];
    //p = plus and m = minus. Example: Ap = A+ and A = A and Am = A-
    int count_Ap = 0, count_A = 0,count_Am = 0,count_Bp = 0,count_B = 0,count_Bm = 0,count_Cp = 0,count_C = 0,count_Cm = 0;
	int count_Dp = 0,count_D = 0,count_F = 0, i;

    //initialising the array
    printf("Enter marks for each student: \n");
    for (i = 0; i<12; i++){
    	printf("Enter %dth student's marks' \n", i+1);
        scanf(" %d", &array[i]);
    }

    //Calculation
    for (i = 0; i<12; i++){

        if (array[i]>=90){
            printf("The %dth student grade is A+\n", i+1);
            count_Ap++;
        }
        else if (array[i]>=86){
            printf("The %dth student grade is A\n", i+1);
            count_A++;
        }
        else if (array[i]>=82){
            printf("The %dth student grade is A-\n", i+1);
            count_Am++;
        }
        else if (array[i]>=78){
            printf("The %dth student grade is B+\n", i+1);
            count_Bp++;
        }
        else if (array[i]>=74){
            printf("The %dth student grade is B\n", i+1);
            count_B++;
        }
        else if (array[i]>=70){
            printf("The %dth student grade is B-\n", i+1);
            count_Bm++;
        }
        else if (array[i]>=66){
            printf("The %dth student grade is C+\n", i+1);
            count_Cp++;
        }
        else if (array[i]>=62){
            printf("The %dth student grade is C\n", i+1);
            count_C++;
        }
        else if (array[i]>=58){
            printf("The %dth student grade is C-\n", i+1);
            count_Cm++;
        }
        else if (array[i]>=54){
            printf("The %dth student grade is D+\n", i+1);
            count_Dp++;
        }
        else if (array[i]>=50){
            printf("The %dth student grade is D\n", i+1);
            count_D++;
        }
        else {
            printf("The %dth student grade is F\n", i+1);
            count_F++;
        }
    }
    
    printf("The number of students who got the following grades is: \nA+ : %d\nA : %d\nA- : %d\nB+ : %d\nB : %d\nB- : %d\nC+ : %d\nC : %d\nC- : %d\nD+ : %d\nD : %d\nF : %d\n", count_Ap, count_A,count_Am,count_Bp,count_B,count_Bm,count_Cp,count_C,count_Cm, count_Dp,count_D,count_F);
    if (count_F > 6) printf("Academic Alert: Poor Performance!");
    return 0;
}
