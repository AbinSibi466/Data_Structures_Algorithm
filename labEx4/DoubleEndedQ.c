#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int num_tickets;
    struct customer *next;
} *front, *rear;

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
        scanf("%s", &newCustomer->name);
        printf("Enter the Number of Tickets: ");
        scanf("%d", &newCustomer->num_tickets);
        numberOfCustomers++;
        newCustomer->next = NULL;

        if (front == NULL)
            front = rear = newCustomer;
        else {
            rear->next = newCustomer;
            rear = newCustomer;
        }

        printf("Want to add more customers (Y/N)?");
        ch = getch();
        if (ch == 'n' || ch == 'N')
            return 0;
    }
}

void displayCustomerQueue() {
    struct customer *temp = front;
    if (temp == NULL) {
        printf("There are no customers!!\n");
        return;
    }
    printf("Customer Queue:\n");
    while (temp != NULL) {
        printf("[%s - %d tickets] <---", temp->name, temp->num_tickets);
        temp = temp->next;
    }
    printf("\n");
}

void bookTicket() {
    struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
    if (newCustomer == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("\nEnter Customer Name: ");
    scanf("%s", &newCustomer->name);
    printf("Enter the Number of Tickets: ");
    scanf("%d", &newCustomer->num_tickets);
    numberOfCustomers++;
    newCustomer->next = NULL;

    if (front == NULL) {
        front = rear = newCustomer;
    } else {
        rear->next = newCustomer;
        rear = newCustomer;
    }
}

void cancelTicket() {
    if (front == NULL) {
        printf("\nThere are no customers");
    } else {
        struct customer *temp = front;
        front = front->next;
        free(temp);
        numberOfCustomers--;
        printf("\nTicket for the first customer canceled\n");
    }
}

void searchCustomerQueue() {
    char search_name[50];
    int pos, foundFlag = 0;
    pos = 0;
    struct customer *temp = front;
    printf("\nEnter name of the customer you want to find: ");
    scanf("%s", &search_name);
    while (temp != NULL) {
        pos++;
        if (strcmpi(search_name, temp->name) == 0) {
            foundFlag = 1;
            printf("\nCustomer Found at position %d\n", pos);
            printf("Name: %s\nNumber of Tickets: %d\n", temp->name, temp->num_tickets);
        }
        temp = temp->next;
    }
    if (foundFlag == 0) {
        printf("\nNo such customer found!\n");
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

int main() {
    int opt;
    opt = 0;
    front = rear = NULL;
    while (1) {
        printf("\n");
        printf(" +------------Ticket Booking Menu------------+\n");
        printf(" | 1. Create Customer Queue                   |\n");
        printf(" | 2. Display Customer Queue                  |\n");
        printf(" | 3. Book Ticket                             |\n");
        printf(" | 4. Cancel Ticket                           |\n");
        printf(" | 5. Search Customer                         |\n");
        printf(" | 6. Exit                                    |\n");
        printf(" +--------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                createCustomer();
                break;
            case 2:
                displayCustomerQueue();
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
