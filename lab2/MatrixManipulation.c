#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

struct movieBookingStruct
{
    char movie_name[25];
    int bookings[ROWS][COLS];
};

struct movieBookingStruct movie;

void insertionDisplay();
int cancelBooking(int row, int col);
void displayBookings();
int findBooking(int value);
void bookTickets();
void mainMenu();

int main()
{
    int choice, value, row, col;
    int continueMenu = 1;

    while (continueMenu)
    {
        mainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Movie Name: ");
            scanf("%s", &movie.movie_name);
            printf("Enter the available seat count:\n");
            insertionDisplay();
            break;
        case 2:
            printf("Enter Row and Column of the seat to cancel: ");
            scanf("%d %d", &row, &col);
            cancelBooking(row - 1, col - 1);
            break;
        case 3:
            displayBookings();
            break;
        case 4:
            printf("Enter the seat number to find: ");
            scanf("%d", &value);
            findBooking(value);
            break;
        case 5:
            printf("BOOK TICKETS\n");
            bookTickets();
            break;
        case 0:
            continueMenu = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void bookTickets()
{
    int row, col;
    printf("Enter Row and Column to book tickets: ");
    scanf("%d %d", &row, &col);

    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
    {
        if (movie.bookings[row - 1][col - 1] == 0)
        {
            movie.bookings[row - 1][col - 1] = 1; // Book the seat
            printf("Ticket booked successfully!\n");
        }
        else
        {
            printf("Seat already booked. Please choose another seat.\n");
        }
    }
    else
    {
        printf("Invalid seat selection. Please choose valid Row and Column.\n");
    }
}

void mainMenu()
{
    printf("Movie_Ticket_Booking\n");
    printf("Enter your Choice (1: New Movie, 2: Cancel Booking, 3: Display Bookings, 4: Find Booking, 5: Book Tickets, 0: Exit): ");
}

void insertionDisplay()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &movie.bookings[i][j]);
        }
    }

    printf("Seat Availability for %s\n", movie.movie_name);
    displayBookings();
}

int cancelBooking(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if (movie.bookings[row][col] == 1)
        {
            movie.bookings[row][col] = 0; // Cancel the booking
            printf("Booking canceled successfully!\n");
        }
        else
        {
            printf("No booking found for the selected seat.\n");
        }
    }
    else
    {
        printf("Invalid seat selection. Please choose valid Row and Column.\n");
    }

    return 0;
}

void displayBookings()
{
    printf("Seat Bookings for %s\n", movie.movie_name);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", movie.bookings[i][j]);
        }
        printf("\n");
    }
}

int findBooking(int value)
{
    printf("Finding Booking\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (movie.bookings[i][j] == value)
            {
                printf("Booking found for seat %d!\n", value);
                return 0;
            }
        }
    }

    printf("No booking found for seat %d.\n", value);
    return 0;
}
