#include <stdio.h>

typedef struct Loan {
    char customerName[50];
    float loanAmount;
    float interestRate;
    int months; // This will now track how long the loan takes
}Loan;

void simulate_repayment(Loan *l, float installment){
    //Base Case
    if(l->loanAmount <= 0){
        printf("\nLoan cleared completely in %d months.\n", l->months);
        return;
    }

    //Safety Check: Prevent infinite loop if installment is too small
    if (l->months == 0){
        float first_interest = l->loanAmount * (l->interestRate / 100.0);
        if(installment <= first_interest && l->months == 0){
            printf("Error: Installment must be greater than monthly interest (%.2f)!\n", first_interest);
            return;//Force exit
        }
    }

    l->months++;

    float interest = l->loanAmount * (l->interestRate / 100.0);
    l->loanAmount = l->loanAmount - installment + interest;

    if(l->loanAmount < 0) l->loanAmount = 0; // Prevent negative balance

    printf("Month %d: Remaining Balance = %.2f\n", l->months, l->loanAmount);

    //Recursive call
    simulate_repayment(l, installment); 
}

int main(){
    Loan l;
    float installment;

    printf("Enter Customer Name: ");
    scanf(" %s", l.customerName); 
    printf("Enter Loan Amount: ");
    scanf(" %f", &l.loanAmount);
    printf("Enter Interest Rate (%%): ");
    scanf(" %f", &l.interestRate);
    printf("Enter Monthly Installment Amount: ");
    scanf(" %f", &installment);

    l.months = 0; // Initialize months to 0

    printf("\n--- Repayment Simulation ---\n");
    simulate_repayment(&l, installment);

    return 0;
}