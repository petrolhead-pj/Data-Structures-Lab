#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char page[50];
    struct node *next;
};

struct node *top = NULL;                //! top ko head ki trah smjho !! just idhr top current position bta rha and will move jbki LL me head fixed hota tha

// Push = Visit New Page  --> insert at head(front as jaise insert kiya top ab wo nayanode bn jayega and agla elemnt fir is top ke pehle insert hoga)..as stack me insertion deletion sb top p hi hota
void push() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter page URL/name: ");
    scanf("%s", newnode->page);

    newnode->next = top;
    top = newnode;

    printf("Visited page %s\n", newnode->page);
}

/* Pop = Go Back */
void pop() {
    if (top == NULL) {
        printf("Stack underflow: No page to go back\n");
        return;
    }

    struct node *temp = top;
    printf("Moved back from page %s\n", temp->page);
    top = top->next;                                        //!top ko head ki trah smjho...delete krna from top means deletiion of head
    free(temp);
}

/* Display browsing history */
void display() {
    if (top == NULL) {
        printf("No web pages visited\n");
        return;
    }

    struct node *temp = top;
    printf("Browsing History:\n");
    while (temp != NULL) {
        printf("%s\n", temp->page);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Visit New Page\n2. Go Back\n3. Display History\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
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
