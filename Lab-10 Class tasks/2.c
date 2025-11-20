#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(){
    char student_names[10][30];
    char temp[30];

    for (int i = 0; i < 10; i++){
        printf("Enter name for student %d: ", i+1);
        scanf(" %30[^\n]", student_names[i]);
    }

    int flag = 1;
    // sorting from a-z
    for (int i = 0; i < 10 && flag == 1; i++){
        flag = 0;
        for (int j = 0; j < 9; j++){
            if (strcasecmp(student_names[j],student_names[j+1]) > 0){
                strcpy(temp, student_names[j]);
                strcpy(student_names[j], student_names[j+1]);
                strcpy(student_names[j+1], temp);
                flag = 1;
            }
        }
    }
    
    printf("Sorted list:\n");
    for (int i = 0; i < 10; i++){
        printf("%s\n", student_names[i]);
    }
    

    return 0;
}