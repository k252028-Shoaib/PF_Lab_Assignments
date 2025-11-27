#include <stdio.h>
#include <stdlib.h>

/*I assumed that the question says that rider can take the tip from the current stop and skip the next stop. Or skip the current stop and take the tip from the next stop*/
int solve_tips(int *tips, int n, int current);

int main(){
    int n, tail = 0;

    printf("Enter number of delivery stops: ");
    scanf(" %d", &n);

    int *tips = (int*)malloc(sizeof(int)*n);
    if(tips == NULL){
        printf("Failed to allocate memory\n");
        return 1;
    }

    for(tail=0; tail<n; tail++){
        printf("Enter tip amount for stop %d: ", tail+1);
        scanf(" %d", tips+tail);
    }

    // Start recursion from index 0 (the first house)
    int max_tip = solve_tips(tips, n, 0);

    printf("Maximum tip collected: %d\n", max_tip);

    free(tips);
    return 0;
}

int solve_tips(int *tips, int n, int current){
    // Base Case: If we go past the last house, no more tips to collect
    if(current >= n) return 0;

    // Option 1: Deliver to current stop.
    // Consequence: We MUST skip the next one (current+1), so we jump to current+2
    int take = *(tips+current) + solve_tips(tips, n, current+2);
    
    // Option 2: Skip current stop.
    // Consequence: We can attempt to deliver to the very next one (current+1)
    int skip = solve_tips(tips, n, current+1);

    // Return the larger of the two options directly
    if(take > skip) return take;
    else return skip;
}
