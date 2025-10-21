#include <stdio.h>

int main()
{
    int array[2][3][3], student[2][3], highest_class_topper[] = {0,0};

    // initialising the arrays
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            student[i][j] = 0;
        }
    }
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                printf("Enter marks for student %d studying subject %d in class %d: ", y + 1, z + 1, x + 1);
                scanf(" %d", &array[x][y][z]);
            }
        }
    }

    // total marks for each student
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                student[x][y] += array[x][y][z];
            }
            // class topper
            if (student[x][highest_class_topper[x]] < student[x][y])
                highest_class_topper[x] = y;
        }
    }

    // overall topper
    if (student[0][highest_class_topper[0]] > student[1][highest_class_topper[1]])
        printf("Top Performer overall is from Class 1 and is Student %d with %d marks\n", highest_class_topper[0] + 1, student[0][highest_class_topper[0]]);
    else
        printf("Top Performer overall is from Class 2 and is Student %d with %d marks\n", highest_class_topper[1] + 1, student[1][highest_class_topper[1]]);

    // output
    printf("Top Performer of Class 1 is Student %d with %d marks\n", highest_class_topper[0] + 1, student[0][highest_class_topper[0]]);
    printf("Top Performer of Class 2 is Student %d with %d marks", highest_class_topper[1] + 1, student[1][highest_class_topper[1]]);
    return 0;
}