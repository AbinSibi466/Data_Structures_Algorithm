#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int priority;
    struct customer* next;
};

struct customer* front = NULL;

void bookTicketWithPriority() {
    struct customer* newCustomer = (struct customer*)malloc(sizeof(struct customer));
    if (newCustomer == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Customer Name: ");
    scanf("%s", newCustomer->name);

    printf("Enter Priority (1 for regular, 2 for VIP, etc.): ");
    scanf("%d", &newCustomer->priority);

    newCustomer->next = NULL;

    if (front == NULL || newCustomer->priority < front->priority) {
        newCustomer->next = front;
        front = newCustomer;
    } else {
        struct customer* temp = front;
        while (temp->next != NULL && temp->next->priority <= newCustomer->priority) {
            temp = temp->next;
        }
        newCustomer->next = temp->next;
        temp->next = newCustomer;
    }

    printf("\nTicket booked for %s with Priority %d!\n", newCustomer->name, newCustomer->priority);
}

void cancelTicket() {
    if (front == NULL) {
        printf("\nThere are no customers in the Priority Queue!\n");
    } else {
        struct customer* temp = front;
        front = front->next;
        free(temp);
        printf("\nHighest Priority Ticket Canceled!\n");
    }
}

void displayPriorityQueue() {
    struct customer* temp = front;

    if (temp == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("[%s, Priority: %d] <-- ", temp->name, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int opt;

    while (1) {
        printf("\n");
        printf(" +-----------Movie Ticket Booking Menu------------+\n");
        printf(" | 1. Book Ticket with Priority                    |\n");
        printf(" | 2. Cancel Highest Priority Ticket               |\n");
        printf(" | 3. Display Priority Queue                       |\n");
        printf(" | 4. Exit                                         |\n");
        printf(" +-------------------------------------------------+\n");
        printf("Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                bookTicketWithPriority();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                displayPriorityQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}
