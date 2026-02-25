#include <stdio.h>
#include <string.h>

int main(){
    char books[10][100];
    char query[100];
    int found = 0;

    for (int i = 0; i < 10; i++){
        printf("Enter title for book %d: ", i+1);
        scanf(" %99[^\n]", books[i]);
    }

    printf("Enter a book title to search: ");
    scanf(" %99[^\n]", query);

    for (int i = 0; i < 10; i++){
        if (strcmp(books[i], query) == 0) {
            printf("Book Found\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book Not Found\n");
    }

    return 0;
}
