#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a booking
typedef struct Booking {
    int seatNumber;
    char customerName[50];
    struct Booking* nextBooking;
} Booking;

// Structure to represent a movie
typedef struct Movie {
    char movieName[50];
    int totalSeats;
    int bookedSeats;
    Booking* bookings;
    struct Movie* nextMovie;
} Movie;

// Function to create a new booking
Booking* createBooking(int seatNumber, const char* customerName) {
    Booking* newBooking = (Booking*)malloc(sizeof(Booking));
    if (newBooking == NULL) {
        printf("Memory allocation error for Booking.\n");
        exit(EXIT_FAILURE);
    }

    newBooking->seatNumber = seatNumber;
    strcpy(newBooking->customerName, customerName);
    newBooking->nextBooking = NULL;

    return newBooking;
}

// Function to create a new movie
Movie* createMovie(const char* movieName, int totalSeats) {
    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    if (newMovie == NULL) {
        printf("Memory allocation error for Movie.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newMovie->movieName, movieName);
    newMovie->totalSeats = totalSeats;
    newMovie->bookedSeats = 0;
    newMovie->bookings = NULL;
    newMovie->nextMovie = NULL;

    return newMovie;
}

// Function to book a seat for a movie
void bookSeat(Movie* movie, int seatNumber, const char* customerName) {
    if (movie->bookedSeats < movie->totalSeats) {
        Booking* newBooking = createBooking(seatNumber, customerName);
        newBooking->nextBooking = movie->bookings;
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
    Booking* currentBooking = movie->bookings;

    while (currentBooking != NULL) {
        printf("Seat %d: %s\n", currentBooking->seatNumber, currentBooking->customerName);
        currentBooking = currentBooking->nextBooking;
    }
}

// Function to display all movies and their bookings
void displayAllMovies(Movie* head) {
    Movie* currentMovie = head;

    while (currentMovie != NULL) {
        printf("------------------\n");
        printf("Movie: %s\n", currentMovie->movieName);
        printf("Total Seats: %d\n", currentMovie->totalSeats);
        printf("Booked Seats: %d\n", currentMovie->bookedSeats);
        displayBookings(currentMovie);
        printf("------------------\n");

        currentMovie = currentMovie->nextMovie;
    }
}

int main() {
    // Create movies
    Movie* movie1 = createMovie("Inception", 50);
    Movie* movie2 = createMovie("The Dark Knight", 40);

    // Book seats
    bookSeat(movie1, 1, "Alice");
    bookSeat(movie1, 5, "Bob");
    bookSeat(movie2, 3, "Charlie");

    // Display all movies and their bookings
    displayAllMovies(movie1);

    // Free memory
    free(movie1);
    free(movie2);

    return 0;
}
