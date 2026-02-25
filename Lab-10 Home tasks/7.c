#include <stdio.h>

int main(){
    char category[100];
    double amount;
    FILE *fp;
    char line[200];

    printf("Enter expense category: ");
    scanf(" %99[^\n]", category);
    printf("Enter amount: ");
    scanf(" %lf", &amount);

    fp = fopen("expenses.txt", "a");
    if (fp == NULL) {
        printf("Error opening expenses.txt\n");
        return 1;
    }
    fprintf(fp, "%s,%.2f\n", category, amount);
    fclose(fp);

    printf("Expense appended to expenses.txt\n\n");
    printf("--- Current expenses ---\n");

    fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("Error opening expenses.txt for reading\n");
        return 1;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = 0;
        while (line[len] != '\0') len++;
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
        printf("%s\n", line);
    }
    fclose(fp);

    return 0;
}
