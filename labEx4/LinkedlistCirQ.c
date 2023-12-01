#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int num_tickets;
    struct customer *next;
} *first, *last;

int numberOfCustomers = 0;

int createCustomer() {
    char ch;
    while (1) {
        struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
        if (newCustomer == NULL) {
            printf("Memory allocation error!!");
            return 0;
        }

        printf("\nEnter Customer Name: ");
        scanf("%s", newCustomer->name);
        printf("Enter the Number of Tickets: ");
        scanf("%d", &newCustomer->num_tickets);

        numberOfCustomers++;
        newCustomer->next = NULL;

        if (first == NULL) {
            first = last = newCustomer;
            last->next = first;
        } else {
            last->next = newCustomer;
            last = newCustomer;
            last->next = first;
        }

        printf("Want to add more customers (Y/N)?");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            return 0;
        }
    }
}

void peekCustomerQueue() {
    struct customer *temp = first;
    if (temp == NULL) {
        printf("There are no customers In Queue!!\n");
        return;
    }

    do {
        printf("[%s - %d tickets]<---", temp->name, temp->num_tickets);
        temp = temp->next;
    } while (temp != first);

    printf("(%s - %d tickets)", last->next->name, last->next->num_tickets);
}

void bookTicket() {
    struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
    if (newCustomer == NULL) {
        printf("Memory allocation error");
        return;
    }

    printf("\nEnter Customer Name: ");
    scanf("%s", newCustomer->name);
    printf("Enter the Number of Tickets: ");
    scanf("%d", &newCustomer->num_tickets);

    numberOfCustomers++;
    newCustomer->next = NULL;

    if (first == NULL) {
        first = last = newCustomer;
        last->next = first;
    } else {
        last->next = newCustomer;
        last = newCustomer;
        last->next = first;
    }
}

void cancelTicket() {
    if (first == NULL) {
        printf("\nThere are no customers in Queue");
    } else {
        struct customer *temp = first;
        first = first->next;
        last->next = first;
        free(temp);
        numberOfCustomers--;
        printf("\nTicket for the first customer canceled\n");
    }
}

void searchCustomerQueue() {
    char search_name[50];
    int foundFlag = 0;
    struct customer *temp = first;

    printf("\nEnter name of the customer you want to find : ");
    scanf("%s", search_name);

    do {
        if (strcmpi(search_name, temp->name) == 0) {
            foundFlag = 1;
            printf("\nCustomer Found!\n");
            printf("Name: %s, Number of Tickets: %d\n", temp->name, temp->num_tickets);
            break;
        }
        temp = temp->next;
    } while (temp != first);

    if (foundFlag == 0) {
        printf("\nNo such customer found In Queue!!\n");
    }
}

void exit_program() {
    struct customer *temp = first;
    while (temp != NULL) {
        struct customer *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;
    opt = 0;
    first = last = NULL;

    while (1) {
        printf("\n");
        printf(" +--------------Movie Ticket Booking Menu--------------+\n");
        printf(" | 1. Create Customer Queue                             |\n");
        printf(" | 2. Peek Customer Queue                               |\n");
        printf(" | 3. Book Ticket                                       |\n");
        printf(" | 4. Cancel Ticket                                     |\n");
        printf(" | 5. Search Customer                                   |\n");
        printf(" | 6. Exit                                              |\n");
        printf(" +-----------------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                createCustomer();
                break;
            case 2:
                peekCustomerQueue();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                searchCustomerQueue();
                break;
            case 6:
                exit_program();
        }
    }
    return 0;
}
