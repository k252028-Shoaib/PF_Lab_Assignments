#include <stdio.h>

int main(){
    char line[200];
    FILE *fp;
    int count = 0;

    fp = fopen("attendance.txt", "r");
    if (fp == NULL) {
        //Create the file if it does not exist
        fp = fopen("attendance.txt", "a");
        fclose(fp);
        fp = fopen("attendance.txt", "r");
        if (fp == NULL)
        {
            printf("Could not open attendance.txt\n");
        }
        
    }

    printf("--- Attendance List ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = 0;
        while (line[len] != '\0') len++;
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
        printf("%s\n", line);
        count++;
    }

    fclose(fp);

    printf("There are %d students in the file\n", count);

    return 0;
}
