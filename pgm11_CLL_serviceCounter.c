#include <stdio.h>
#include <stdlib.h>

struct node {
    int cust_id;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Enqueue = Add customer */
void enqueue() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &newnode->cust_id);

    if (front == NULL) {
        // First customer
        front = rear = newnode;
        newnode->next = newnode;   // circular link
    } else {
        rear->next = newnode;
        newnode->next = front;
        rear = newnode;
    }

    printf("Customer added to queue\n");
}

/* Dequeue = Serve customer */
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow: No customers to serve\n");
        return;
    }

    struct node *temp = front;

    printf("Serving Customer ID: %d\n", temp->cust_id);

    if (front == rear) {
        // Only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

/* Display queue */
void display() {
    if (front == NULL) {
        printf("No customers in queue\n");
        return;
    }

    struct node *temp = front;
    printf("Customers in queue:\n");

    do {
        printf("%d\n", temp->cust_id);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Enter a valid choice\n");
        }
    }
}
