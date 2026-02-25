#include <stdio.h>

void book_seat(int *arr, int size); // display seat map

int main(){
    int flight_1[3] = {0}; // 3 seats
    int flight_2[4] = {0}; // 4 seats
    int flight_3[5] = {0}; // 5 seats
    int *flights[] = {flight_1,flight_2,flight_3};
    int size[] = {3,4,5};
    int flight_choice;
    char Continue;

    do
    {
        printf("Which flight will you chooose? (1/2/3): ");
        scanf(" %d", &flight_choice);
        book_seat(flights[flight_choice-1], size[flight_choice-1]);

        printf("Do you want to conintue? (y/n): ");
        scanf(" %c", &Continue);
    } while (Continue == 'y');
    
    for (int i = 0; i < 3; i++){
        int count = 0;
        for (int j = 0; j < size[i]; j++){
            if (*(*(flights + i) + j) == 1) count++;
        }
        printf("Total occupied seats for flight %d are %d\n",i+1, count);        
    }

    return 0;
}

void book_seat(int *arr, int size){
    int seat_choice, booking_choice;
    printf("Status for all seats on the flight: \n");
    for (int i = 0; i<size; i++){
        if (*(arr + i) == 0) printf("Seat %d: Available\n", i+1);
        if (*(arr + i) == 1) printf("Seat %d: Booked\n", i+1);
    }
    printf("Do you want to book or cancel? (enter 1 to book and 0 to cancel): ");
    scanf(" %d", &booking_choice);

    if(booking_choice == 1){
        printf("Which seat do you want to book? (enter seat number): ");
        scanf(" %d", &seat_choice);
        *(arr + seat_choice - 1) = 1;
    }
    else if(booking_choice == 0){
        printf("Which seat do you want to cancel? (enter seat number): ");
        scanf(" %d", &seat_choice);
        *(arr + seat_choice - 1) = 0;
    }
    else printf("Wrong input\n");
}