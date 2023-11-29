#include <stdio.h>
#include <string.h>

struct movie {
    int id;
    char title[50];
    char genre[20];
    float rating;
};

struct showtime {
    int movieId;
    char time[10];
    int availableSeats;
};

struct booking {
    int showtimeId;
    int numTickets;
};

// Function to add a new movie
void addMovie(struct movie *movies, int id) {
    printf("Enter the details for Movie %d:\n", id + 1);
    movies->id = id + 1;
    printf("Title: ");
    scanf("%s", movies->title);
    printf("Genre: ");
    scanf("%s", movies->genre);
    printf("Rating: ");
    scanf("%f", &movies->rating);
}

// Function to add a new showtime
void addShowtime(struct showtime *showtimes, struct movie *movies, int id) {
    printf("Enter the details for Showtime %d:\n", id + 1);
    showtimes->movieId = id + 1;
    printf("Time: ");
    scanf("%s", showtimes->time);
    printf("Available Seats: ");
    scanf("%d", &showtimes->availableSeats);
}

// Function to book tickets
void bookTickets(struct booking *bookings, struct showtime *showtimes, int id) {
    printf("Enter the details for Booking %d:\n", id + 1);
    bookings->showtimeId = id + 1;
    printf("Number of Tickets: ");
    scanf("%d", &bookings->numTickets);

    // Update available seats
    showtimes[id].availableSeats -= bookings->numTickets;
    printf("Tickets booked successfully!\n");
}

// Function to show movie details
void showMovieDetails(struct movie *movies) {
    printf("\n-------------Movie %d----------------", movies->id);
    printf("\nTitle : %s \nGenre : %s\nRating : %.2f\n", movies->title, movies->genre, movies->rating);
    printf("-------------------------------------\n");
}

// Function to show showtime details
void showShowtimeDetails(struct showtime *showtimes) {
    printf("\n-------------Showtime %d----------------", showtimes->movieId);
    printf("\nTime : %s \nAvailable Seats : %d\n", showtimes->time, showtimes->availableSeats);
    printf("----------------------------------------\n");
}

int main() {
    struct movie movies[100];
    struct showtime showtimes[100];
    struct booking bookings[100];
    int movieCount = 0, showtimeCount = 0, bookingCount = 0;
    int choice;

    do {
        // Menu for movie ticket booking application
        printf("\n+-----------------------Menu-----------------------+\n");
        printf("| 1. Add Movie                                      |\n");
        printf("| 2. Add Showtime                                   |\n");
        printf("| 3. Book Tickets                                   |\n");
        printf("| 4. Show Movie Details                             |\n");
        printf("| 5. Show Showtime Details                          |\n");
        printf("| 6. Exit                                           |\n");
        printf("+---------------------------------------------------+\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        // Choice based if-else-if ladder
        switch (choice) {
            case 1:
                addMovie(&movies[movieCount++], movieCount);
                break;
            case 2:
                addShowtime(&showtimes[showtimeCount++], &movies[movieCount - 1], showtimeCount);
                break;
            case 3:
                if (showtimeCount > 0) {
                    bookTickets(&bookings[bookingCount++], &showtimes[showtimeCount - 1], bookingCount);
                } else {
                    printf("No showtimes available. Add showtimes first.\n");
                }
                break;
            case 4:
                if (movieCount > 0) {
                    int i;
                    for (i = 0; i < movieCount; i++)
                        showMovieDetails(&movies[i]);
                } else {
                    printf("No movies available.\n");
                }
                break;
            case 5:
                if (showtimeCount > 0) {
                    int i;
                    for (i = 0; i < showtimeCount; i++)
                        showShowtimeDetails(&showtimes[i]);
                } else {
                    printf("No showtimes available.\n");
                }
                break;
            case 6:
                printf("Exiting the Movie Ticket Booking Application.\n");
                break;
            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}