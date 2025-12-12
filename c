#include <stdio.h>
#include <string.h>

#define MAX 50   // maximum bookings

// Structure for booking
struct Booking {
    int ticket_id;
    int bus_id;
    char name[30];
    int seat_no;
};

// Structure for bus
struct Bus {
    int id;
    char from[20];
    char to[20];
    int total_seats;
};

// Hardcoded buses
struct Bus buses[3] = {
    {1, "CityA", "CityB", 40},
    {2, "CityA", "CityC", 30},
    {3, "CityB", "CityD", 35}
};

struct Booking bookings[MAX];
int count = 0;     // number of bookings
int next_ticket = 1; // for generating ticket numbers

// Function to display buses
void show_buses() {
    printf("\nAvailable Buses:\n");
    printf("ID   From    To      Seats\n");
    printf("--------------------------------\n");
    for(int i=0; i<3; i++) {
        printf("%d    %s    %s    %d\n",
               buses[i].id, buses[i].from, buses[i].to, buses[i].total_seats);
    }
}

// Function to book ticket
void book_ticket() {
    if(count >= MAX) {
        printf("Booking limit reached!\n");
        return;
    }

    int bus_id, seat_no;
    char name[30];

    show_buses();
    printf("\nEnter Bus ID: ");
    scanf("%d", &bus_id);

    printf("Enter Seat Number: ");
    scanf("%d", &seat_no);

    printf("Enter Passenger Name: ");
    scanf("%s", name);

    bookings[count].ticket_id = next_ticket++;
    bookings[count].bus_id = bus_id;
    bookings[count].seat_no = seat_no;
    strcpy(bookings[count].name, name);

    printf("\nTicket Booked Successfully!\n");
    printf("Your Ticket ID = %d\n", bookings[count].ticket_id);

    count++;
}

// Function to cancel ticket
void cancel_ticket() {
    int t_id;
    printf("\nEnter Ticket ID to cancel: ");
    scanf("%d", &t_id);

    int found = -1;
    for(int i=0; i<count; i++) {
        if(bookings[i].ticket_id == t_id) {
            found = i;
            break;
        }
    }

    if(found == -1) {
        printf("Ticket not found!\n");
        return;
    }

    // shift bookings
    for(int i=found; i<count-1; i++) {
        bookings[i] = bookings[i+1];
    }
    count--;

    printf("Ticket %d cancelled successfully!\n", t_id);
}

// Function to display all bookings
void display_bookings() {
    if(count == 0) {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nAll Bookings:\n");
    printf("TicketID   BusID   Name       Seat\n");
    printf("----------------------------------------\n");

    for(int i=0; i<count; i++) {
        printf("%d          %d        %s        %d\n",
               bookings[i].ticket_id,
               bookings[i].bus_id,
               bookings[i].name,
               bookings[i].seat_no);
    }
}

// Main menu
int main() {
    int choice;

    while(1) {
        printf("\n==== BUS TICKET BOOKING SYSTEM ====\n");
        printf("1. Show Buses\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display Bookings\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: show_buses(); break;
            case 2: book_ticket(); break;
            case 3: cancel_ticket(); break;
            case 4: display_bookings(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
