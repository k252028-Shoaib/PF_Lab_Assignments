#include <stdio.h>
#include <string.h>

int main(){
    char guest[10][100];
    int rooms[10];
    int n, i;
    FILE *fp;
    char line[200];
    char search[100];
    int found = 0;

    printf("How many bookings to enter (max 10): ");
    scanf(" %d", &n);
    if (n < 1) n = 1;
    if (n > 10) n = 10;

    for (i = 0; i < n; i++){
        printf("Enter guest name %d: ", i+1);
        scanf(" %99[^\n]", guest[i]);
        printf("Enter room number for %s: ", guest[i]);
        scanf(" %d", &rooms[i]);
    }

    fp = fopen("hotel.txt", "a");
    if (fp == NULL) {
        printf("Error opening hotel.txt\n");
        return 1;
    }
    for (i = 0; i < n; i++){
        fprintf(fp, "%s,%d\n", guest[i], rooms[i]);
    }
    fclose(fp);

    printf("Records stored in hotel.txt\n");

    printf("Enter a guest name to search: ");
    scanf(" %99[^\n]", search);

    fp = fopen("hotel.txt", "r");
    if (fp == NULL) {
        printf("Error opening hotel.txt for reading\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL){
        char name[100];
        int room;
        if (sscanf(line, " %99[^,],%d", name, &room) == 2) {
            if (strcmp(name, search) == 0) {
                printf("%s is in room %d\n", name, room);
                found = 1;
                break;
            }
        }
    }
    fclose(fp);

    if (!found) {
        printf("Guest not found\n");
    }

    return 0;
}
