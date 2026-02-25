#include <stdio.h>
#include <string.h>

int main (){
    char feedback[1000];
    printf("Please enter your feedback of upto 999 characters: ");
    scanf("%999[^\n]", feedback);

    int count =0;
    char *ptr = (char*)feedback;//giving the pointer an initial value
    
    while ((ptr = strstr(ptr, "bad")) != NULL) // assign the pointer the return value of strstr, if bad is found then the return value is the pointer/address from the start of the word "bad"
    {
        count++;
        ptr += 3;//start it after the word "bad"
    }

    printf("count: %d\n", count);
    int size = strlen(feedback) - (count * 3) /*remove space for "bad"*/ + (count * 8) /*add spaces for "not good"*/ + 1 /*for "\0"*/;
    printf("%d\n", size);
    char new[size];
    char*new_ptr = new;
    char*feedback_ptr = feedback;

    while (*feedback_ptr != '\0'){
        char *match = strstr(feedback_ptr, "bad");

        if (match == NULL) {
            // No more matches found: Copy the rest of the text and break
            strcpy(new_ptr, feedback_ptr);
            break;
        }
        int no_char = match-feedback_ptr; //match - feedback us the number of characters till the word bad
        strncpy(new_ptr, feedback_ptr, no_char);
        new_ptr += no_char;
        strcpy(new_ptr,"not good");
        new_ptr += 8;

        feedback_ptr = match + 3;//move pointer to the address right after bad
    }
    
    printf("upadted feedback: \n%s", new);
    return 0;
}