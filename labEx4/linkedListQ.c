#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    struct customer *next;
} *front, *rear;

int numberOfCustomers = 0;

int bookTicket() {
    char ch;
    while (1) {
        struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
        if (newCustomer == NULL) {
            printf("Memory allocation error!!");
            return 0;
        }

        printf("\nEnter Customer Name: ");
        scanf("%s", newCustomer->name);

        numberOfCustomers++;
        newCustomer->next = NULL;

        if (front == NULL) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }

        printf("Want to book tickets for more customers (Y/N)?");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            return 0;
        }
    }
}

void displayCustomerList() {
    struct customer *temp = front;
    if (temp == NULL) {
        printf("There are no customers In Queue!!\n");
        return;
    }

    while (temp != NULL) {
        printf("[%s]<---", temp->name);
        temp = temp->next;
    }

    printf("\n");
}

void bookTicketForMovie() {
    char ch;
    while (1) {
        struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
        if (newCustomer == NULL) {
            printf("Memory allocation error!!");
            return;
        }

        printf("\nEnter Customer Name: ");
        scanf("%s", newCustomer->name);

        numberOfCustomers++;
        newCustomer->next = NULL;

        if (front == NULL) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }

        printf("Want to book tickets for more customers (Y/N)?");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            return;
        }
    }
}

void cancelTicket() {
    if (front == NULL) {
        printf("\nThere are no customers in Queue");
    } else {
        struct customer *temp = front;
        front = front->next;
        free(temp);
        numberOfCustomers--;
        printf("\nTicket for the first customer canceled\n");
    }
}

void searchCustomer() {
    char search_name[50];
    int foundFlag = 0;
    struct customer *temp = front;

    printf("\nEnter name of the customer you want to find: ");
    scanf("%s", search_name);

    while (temp != NULL) {
        if (strcmpi(search_name, temp->name) == 0) {
            foundFlag = 1;
            printf("\nCustomer Found!\n");
            printf("Name: %s\n", temp->name);
            break;
        }
        temp = temp->next;
    }

    if (foundFlag == 0) {
        printf("\nNo customer found with the given name in Queue!!\n");
    }
}

void exit_program() {
    struct customer *temp = front;
    while (temp != NULL) {
        struct customer *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

void main() {
    int opt;
    opt = 0;
    front = rear = NULL;

    while (1) {
        printf("\n");
        printf(" +--------------Movie Ticket Booking Menu--------------+\n");
        printf(" | 1. Book Tickets for Movie                            |\n");
        printf(" | 2. Display Customer List                             |\n");
        printf(" | 3. Book Tickets for Another Movie                     |\n");
        printf(" | 4. Cancel Ticket                                       |\n");
        printf(" | 5. Search Customer                                    |\n");
        printf(" | 6. Exit                                              |\n");
        printf(" +-----------------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayCustomerList();
                break;
            case 3:
                bookTicketForMovie();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                searchCustomer();
                break;
            case 6:
                exit_program();
        }
    }
}
