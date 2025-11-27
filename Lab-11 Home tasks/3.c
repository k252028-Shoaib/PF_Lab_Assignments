#include <stdio.h>
#include <stdlib.h>

struct Patient {
    char name[50];
    int age;
    int healthScore;
};

struct DailyReport {
    int day;
    int scoreChange;
};

void compute_final_score(struct Patient *p, struct DailyReport *reports, int total_days, int current){
    if(current == total_days) return;

    p->healthScore += (reports+current)->scoreChange;

    compute_final_score(p, reports, total_days, current+1);
}

int main(){
    struct Patient p;
    int n, tail = 0;

    printf("Enter Patient Name: ");
    scanf(" %s", p.name);
    printf("Enter Age: ");
    scanf(" %d", &p.age);
    printf("Enter Initial Health Score: ");
    scanf(" %d", &p.healthScore);

    printf("Enter number of days to record: ");
    scanf(" %d", &n);

    struct DailyReport *reports = (struct DailyReport*)malloc(sizeof(struct DailyReport)*n);
    if(reports == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for(tail=0; tail<n; tail++){
        (reports+tail)->day = tail+1;
        printf("Enter score change for Day %d: ", tail+1);
        scanf(" %d", &(reports+tail)->scoreChange);
    }

    compute_final_score(&p, reports, n, 0);

    printf("\nFinal Health Score for %s: %d\n", p.name, p.healthScore);

    free(reports);
    return 0;
}