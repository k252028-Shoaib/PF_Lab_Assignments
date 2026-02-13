#include <stdio.h>

int main() {
    float PF, AP, Cal, FE, ICP, IST, ICT , total, percentage, CGPA = 0.0f;

    // Input data
    printf("Enter marks for PF: ");
    scanf("%f", &PF);

    printf("Enter marks for AP: ");
    scanf("%f", &AP);

    printf("Enter marks for Cal: ");
    scanf("%f", &Cal);

    printf("Enter marks for FE: ");
    scanf("%f", &FE);

    printf("Enter marks for ICP: ");
    scanf("%f", &ICP);

    printf("Enter marks for IST: ");
    scanf("%f", &IST);

    printf("Enter marks for ICT: ");
    scanf("%f", &ICT);

    // Calculation
    total = PF + AP + Cal + FE + ICP + IST + ICT;
    percentage = (total / 700) * 100;
    CGPA = (percentage / 100) * 4;

    // Output
    printf("---------------------------\n STUDENT RESULT \n---------------------------\n");
    printf("Marks obtained:\n");
    printf("PF: %.1f\nAP: %.1f\nCal: %.1f\nFE: %.1f\nICP: %.1f\nIST: %.1f\nICT: %.1f\n",
           PF, AP, Cal, FE, ICP, IST, ICT);
    printf("Total      : %.1f\n", total);
    printf("Percentage : %.2f%%\n", percentage);
    printf("CGPA       : %.2f/4.00\n", CGPA);
    printf("---------------------------\n");

    return 0;
}
