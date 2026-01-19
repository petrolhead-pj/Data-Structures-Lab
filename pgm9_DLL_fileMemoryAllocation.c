#include <stdio.h>
#include <stdlib.h>

struct node {
    int file_no;
    int mem_size;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert new file at front */
void insert_front() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter file number: ");
    scanf("%d", &newnode->file_no);
    printf("Enter memory size: ");
    scanf("%d", &newnode->mem_size);

   if(head==NULL) head=newnode;
    else {
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

/* Delete file at a given position */
void delete_position() {
    if (head == NULL) {
        printf("No files in memory\n");
        return;
    }

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    struct node *temp = head;

    if (pos == 1) {         //means head hi delete krna hai
        head = temp->next;
        head->prev = NULL;
        printf("File %d removed\n", temp->file_no);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++)               //temp is the node to be deleeted
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;                          
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("File %d removed\n", temp->file_no);
    free(temp);
}

/* Display memory allocation */
void display() {
    if (head == NULL) {
        printf("No files allocated in memory\n");
        return;
    }

    struct node *temp = head;
    printf("File Memory Allocation:\n");
    while (temp != NULL) {
        printf("File No: %d | Memory Size: %d KB\n",
               temp->file_no, temp->mem_size);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert File\n2. Delete File (by position)\n3. Display Files\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_front();
                break;

            case 2:
                delete_position();
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
