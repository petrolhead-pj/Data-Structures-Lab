#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

/* Insert term at the end */
struct Node* insertEnd(struct Node *head, int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Read polynomial */
struct Node* readPoly() {
    int n, coeff, exp;
    struct Node *head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }
    return head;
}

/* Add two polynomials */
struct Node* addPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insertEnd(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insertEnd(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insertEnd(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertEnd(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

/* Display polynomial */
void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("\nEnter first polynomial (sorted by exponent):\n");
    poly1 = readPoly();
    display(poly1);

    printf("\nEnter second polynomial (sorted by exponent):\n");
    poly2 = readPoly();
    display(poly2);

    sum = addPoly(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(sum);

    return 0;
}
