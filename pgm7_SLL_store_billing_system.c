#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int cust_id;
    struct node *next;
};                                  //!remember the semicolon at the last of the struct

struct node *head = NULL;

// Insert at end (customer arrives)
void insert_end(int id) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));          //ek naya pointer node bnaya
    newnode->cust_id = id;
    newnode->next = NULL;

    if (head == NULL) {             //means the LL was empty and this is the first node
        head = newnode;             //pointed head to this first node
        return;
    }

    struct node *temp = head;         //ab end me insert krna hai toh to last wale node ko new node p point kr denge, temp node ko traverse krke last node tk phucha rhe
    while (temp->next != NULL)        //last node whi hoga jiska next NULL point kr rha ho, jaise ho waise hi stop 
        temp = temp->next;

    temp->next = newnode;             //temp now stores the last node
}

// Delete from beginning (billing completed)
void delete_begin() {
    if (head == NULL) {
        printf("Queue is empty. No customer to bill.\n");
        return;
    }

    struct node *temp = head;           //storing the first node which is to be deleted so that we can free it at last
    printf("Billing completed for Customer ID: %d\n", temp->cust_id);
    head = head->next;                  //head ko agle node pe point krwa diya
    free(temp);
}

// Display customer list
void display() { 
    if (head == NULL) {
        printf("Customer queue is empty.\n");
        return;
    }
    
    struct node *temp = head;               //we can't change the value of head(for future operations) that's why we don't do head=head->next in the while loop!! that's why we store the node in temp and then traverse
    printf("Customer Queue: ");
    while (temp != NULL) {                  //traversing through the LL until the node points to NULL as that would be the last node
        printf("%d -> ", temp->cust_id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, id;

    while (1) {
        printf("\n1.Customer Arrives 2.Complete Billing 3.Display Queue 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                insert_end(id);
                display();
                break;

            case 2:
                delete_begin();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
