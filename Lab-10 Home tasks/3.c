#include <stdio.h>
#include <string.h>

int main(){
    char city[5][100];
    double temp[5];
    FILE *fp;
    char name[100];
    double t;
    int i;
    int highest_idx = 0;

    for (i = 0; i < 5; i++){
        printf("Enter name of city %d: ", i+1);
        scanf(" %99[^\n]", city[i]);
        printf("Enter average temperature for %s: ", city[i]);
        scanf(" %lf", &temp[i]);
    }

    fp = fopen("temperature.txt", "w");
    if (fp == NULL) {
        printf("Error opening temperature.txt\n");
        return 1;
    }
    for (i = 0; i < 5; i++){
        fprintf(fp, "%s,%.2f\n", city[i], temp[i]);
    }
    fclose(fp);

    /* read back and find highest */
    fp = fopen("temperature.txt", "r");
    if (fp == NULL) {
        printf("Error opening temperature.txt for reading\n");
        return 1;
    }

    i = 0;
    while (fscanf(fp, " %99[^,],%lf\n", name, &t) == 2) {
        if (i == 0 || t > temp[highest_idx]) {
            /* find matching index in temp array (simple approach) */
            int j;
            for (j = 0; j < 5; j++){
                if (strcmp(name, city[j]) == 0) {
                    highest_idx = j;
                    break;
                }
            }
        }
        i++;
    }
    fclose(fp);

    printf("City with the highest temperature: %s (%.2f)\n", city[highest_idx], temp[highest_idx]);

    return 0;
}
