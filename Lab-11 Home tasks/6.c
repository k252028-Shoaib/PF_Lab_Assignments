#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
    char name[50];
    int age;
}Person;

typedef struct Student{
    Person p; //nested structure
    int creditHours; //Total credits
    float perCreditFee;
}Student;

float compute_fee(int *credits, int n, float rate);

int main(){
    Student s;
    int n, tail = 0;

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.p.name);
    printf("Enter Age: ");
    scanf(" %d", &s.p.age);
    printf("Enter Fee Per Credit Hour: ");
    scanf(" %f", &s.perCreditFee);

    printf("Enter number of subjects: ");
    scanf(" %d", &n);

    int *subject_credits = (int*)malloc(sizeof(int)*n);
    if(subject_credits == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for(tail=0; tail<n; tail++){
        printf("Enter credits for subject %d: ", tail+1);
        scanf(" %d", subject_credits+tail);
    }

    // Passing n-1 because array index is 0 to n-1
    float total_fee = compute_fee(subject_credits, n-1, s.perCreditFee);

    printf("\nStudent: %s\nTotal Semester Fee: %.2f\n", s.p.name, total_fee);

    free(subject_credits);
    return 0;
}

float compute_fee(int *credits, int n, float rate){
    if(n < 0) return 0; //Base case: no subjects left

    return compute_fee(credits, n-1, rate) + (rate * *(credits+n));
}