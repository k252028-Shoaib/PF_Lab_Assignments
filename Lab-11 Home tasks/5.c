#include <stdio.h>

typedef struct File{
    char fileName[50];
    float originalSize; //in MB
    float reductionRate; //decimal percentage
}File;

float estimate_size(File *f, int k);

int main(){
    File f;
    int k;

    printf("Enter File Name: ");
    scanf(" %[^\n]", f.fileName);
    printf("Enter Original Size (MB): ");
    scanf(" %f", &f.originalSize);
    printf("Enter Reduction Rate (e.g. 0.1 for 10%%): ");
    scanf(" %f", &f.reductionRate);

    printf("Enter number of compression passes (k): ");
    scanf(" %d", &k);

    float final_size = estimate_size(&f, k);

    printf("Final size of %s after %d passes: %.2f MB\n", f.fileName, k, final_size);
    return 0;
}

float estimate_size(File *f, int k){
    //Base Case:
    if(k == 0) return f->originalSize;

    float prev_size = estimate_size(f, k-1);
    float reduction = prev_size * f->reductionRate;
    
    return prev_size - reduction;
}