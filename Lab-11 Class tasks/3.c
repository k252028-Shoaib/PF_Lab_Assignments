#include <stdio.h>
#include <string.h>
typedef struct Category Category;


typedef struct {
    char name[50];
    int days;
    Category *category;
} Product;


struct Category {
    char name[50];
    char dept[50];
    Product items[5];
    int count;
};


void checkProd(Category *c, int i, int n) {
    if (i >= c->count) return;

    if (c->items[i].days <= n)
    printf("%s (Category: %s) expires in %d days\n", c->items[i].name, c->name, c->items[i].days);

    checkProd(c, i + 1, n);
}


void checkCategories(Category arr[], int i, int total, int n) {
    if (i >= total) return;

    checkProd(&arr[i], 0, n);
    checkCategories(arr, i + 1, total, n);
}


int main() {
    Category c[2];
    int N;

    strcpy(c[0].name, "Dairy"); 
    strcpy(c[0].dept, "Grocery");
    c[0].count = 2;
    strcpy(c[0].items[0].name, "Milk"); 
    c[0].items[0].days = 3; 
    c[0].items[0].category = &c[0];
    strcpy(c[0].items[1].name, "Cheese");
    c[0].items[1].days = 12; 
    c[0].items[1].category = &c[0];

    strcpy(c[1].name, "Bakery"); 
    strcpy(c[1].dept, "Grocery");
    c[1].count = 2;
    strcpy(c[1].items[0].name, "Bread"); 
    c[1].items[0].days = 1; 
    c[1].items[0].category = &c[1];
    strcpy(c[1].items[1].name, "Cake"); 
    c[1].items[1].days = 5; 
    c[1].items[1].category = &c[1];

    printf("Enter N days: ");
    scanf(" %d", &N);

    checkCategories(c, 0, 2, N);
    return 0;
}