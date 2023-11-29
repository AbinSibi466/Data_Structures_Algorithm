#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a booking
typedef struct Booking {
    int seatNumber;
    char customerName[50];
    struct Booking* nextBooking;
    struct Booking* prevBooking;
} Booking;

// Structure to represent a movie
typedef struct Movie {
    char movieName[50];
    int totalSeats;
    int bookedSeats;
    Booking* bookings;
    struct Movie* nextMovie;
    struct Movie* prevMovie;
} Movie;

// Function to create a new booking
Booking* createBooking(int seatNumber, const char* customerName) {
    Booking* newBooking = (Booking*)malloc(sizeof(Booking));
    if (newBooking == NULL) {
        printf("Memory allocation error for Booking.\n");
        return NULL;
    }

    newBooking->seatNumber = seatNumber;
    strcpy(newBooking->customerName, customerName);
    newBooking->nextBooking = NULL;
    newBooking->prevBooking = NULL;

    return newBooking;
}

// Function to create a new movie
Movie* createMovie(const char* movieName, int totalSeats) {
    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    if (newMovie == NULL) {
        printf("Memory allocation error for Movie.\n");
        return NULL;
    }

    strcpy(newMovie->movieName, movieName);
    newMovie->totalSeats = totalSeats;
    newMovie->bookedSeats = 0;
    newMovie->bookings = NULL;
    newMovie->nextMovie = NULL;
    newMovie->prevMovie = NULL;

    return newMovie;
}

// Function to book a seat for a movie
void bookSeat(Movie* movie, int seatNumber, const char* customerName) {
    if (movie->bookedSeats < movie->totalSeats) {
        Booking* newBooking = createBooking(seatNumber, customerName);

        // Check for memory allocation failure
        if (newBooking == NULL) {
            printf("Booking failed due to memory allocation error.\n");
            return;
        }

        // Insert at the beginning of the doubly circular linked list
        if (movie->bookings == NULL) {
            newBooking->nextBooking = newBooking;
            newBooking->prevBooking = newBooking;
        } else {
            newBooking->nextBooking = movie->bookings;
            newBooking->prevBooking = movie->bookings->prevBooking;
            movie->bookings->prevBooking->nextBooking = newBooking;
            movie->bookings->prevBooking = newBooking;
        }

        movie->bookings = newBooking;
        movie->bookedSeats++;
        printf("Seat booked successfully for %s.\n", customerName);
    } else {
        printf("Sorry, all seats are booked for %s.\n", movie->movieName);
    }
}

// Function to display bookings for a movie
void displayBookings(Movie* movie) {
    printf("Bookings for %s:\n", movie->movieName);
    if (movie->bookings != NULL) {
        Booking* currentBooking = movie->bookings;
        do {
            printf("Seat %d: %s\n", currentBooking->seatNumber, currentBooking->customerName);
            currentBooking = currentBooking->nextBooking;
        } while (currentBooking != movie->bookings);
    }
}

// Function to display all movies and their bookings
void displayAllMovies(Movie* head) {
    Movie* currentMovie = head;

    do {
        printf("------------------\n");
        printf("Movie: %s\n", currentMovie->movieName);
        printf("Total Seats: %d\n", currentMovie->totalSeats);
        printf("Booked Seats: %d\n", currentMovie->bookedSeats);
        displayBookings(currentMovie);
        printf("------------------\n");

        currentMovie = currentMovie->nextMovie;
    } while (currentMovie != head);
}

// Function to free memory for a movie and its bookings
void freeMovie(Movie* movie) {
    Booking* currentBooking = movie->bookings;
    Booking* nextBooking;

    // Free bookings
    do {
        nextBooking = currentBooking->nextBooking;
        free(currentBooking);
        currentBooking = nextBooking;
    } while (currentBooking != movie->bookings);

    // Free movie
    free(movie);
}

int main() {
    // Create movies
    Movie* movie1 = createMovie("Inception", 50);
    if (movie1 == NULL) {
        printf("Program terminated due to memory allocation error.\n");
        return EXIT_FAILURE;
    }

    Movie* movie2 = createMovie("The Dark Knight", 40);
    if (movie2 == NULL) {
        printf("Program terminated due to memory allocation error.\n");
        freeMovie(movie1);
        return EXIT_FAILURE;
    }

    // Book seats
    bookSeat(movie1, 1, "Alice");
    bookSeat(movie1, 5, "Bob");
    bookSeat(movie2, 3, "Charlie");

    // Display all movies and their bookings
    displayAllMovies(movie1);

    // Free memory
    freeMovie(movie1);
    freeMovie(movie2);

    return EXIT_SUCCESS;
}
