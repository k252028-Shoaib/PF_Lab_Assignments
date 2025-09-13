#include <stdio.h>
#include <math.h>

int main() {
    float Loan_amount, Annual_interest_rate, EMI = 0.0f;
    double r, n = 0.0;
    int Loan_duration = 0;

    // Input data
    printf("Enter Loan amount: ");
    scanf("%f", &Loan_amount);

    printf("Enter Annual interest rate: ");
    scanf("%f", &Annual_interest_rate);

    printf("Enter Loan duration (years): ");
    scanf("%d", &Loan_duration);

    // Calculation
    r = Annual_interest_rate / 1200;    
    n = Loan_duration * 12;          

    EMI = (Loan_amount * r * pow((1 + r), n)) / (pow((1 + r), n) - 1);

    // Output
    printf("---------------------------\n     LOAN CALCULATION     \n---------------------------\n");
    printf("Loan Amount    : %.2f\n", Loan_amount);
    printf("Duration       : %d years (%.0f months)\n", Loan_duration, n);
    printf("Interest rate  : %.2f%% per year\n", Annual_interest_rate);
    printf("Monthly EMI    : %.2f\n", EMI);
    printf("---------------------------\n");

    return 0;
}
