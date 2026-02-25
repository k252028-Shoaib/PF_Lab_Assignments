#include <stdio.h>

int main(){
    char name[100];
    double price;
    int qty;
    FILE *fp;

    printf("Enter product name: ");
    scanf(" %99[^\n]", name);
    printf("Enter price: ");
    scanf(" %lf", &price);
    printf("Enter quantity: ");
    scanf(" %d", &qty);

    fp = fopen("products.txt", "a");
    if (fp == NULL) {
        printf("Error opening products.txt\n");
        return 1;
    }

    fprintf(fp, "%s,%.2f,%d\n", name, price, qty);
    fclose(fp);

    printf("Product stored successfully in products.txt\n");

    return 0;
}
