//Write a C program to implement a Stack data structure using arrays, where each pushed number represents a web page visited. When a new web 
//page is visited,push its page number onto the stack.When the user moves backward, pop and display the page number removed from the stack. 
//Use a structure to represent the Stack. Handle and display appropriate messages for stack overflow and underflow conditions

//!We have to use a structure it is written so the req code is:
#include<stdio.h>
#define SIZE 50

struct Stack {            //here sizes and top are declared inside the structure
    int pages[SIZE];      //each number represents a web page
    int top;
};

int isEmpty(struct Stack *s){       //one *s means it is the actual array so you think it of int isEmpty(int arr[]) {....}
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *s){
    if(s->top == SIZE-1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int page){
    if(isFull(s))
        printf("Stack overflow\n");
    else{
        s->pages[++s->top] = page;          //instead of pages[++top]=page;  
        printf("Visited page %d\n", page);
    }
}

int pop(struct Stack *s){
    if(isEmpty(s))
        return -1;
    else
        return s->pages[s->top--];          //instead of return pages[top--];
}

void display(struct Stack *s){
    if(isEmpty(s))
        printf("No web pages\n");
    else{
        for(int i = s->top; i >= 0; i--){
            printf("Page %d\n", s->pages[i]);
        }
    }
}

int main(){
    struct Stack s;
    s.top = -1;

    int choice, page;
    int n = 1;

    while(n){
        printf("\n1.Visit New Page\n2.Go Back\n3.Display History\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter page number to visit: ");
                scanf("%d",&page);
                push(&s, page);
                break;

            case 2:
                if(isEmpty(&s))
                    printf("Stack underflow: No page to go back\n");
                else{
                    int removed = pop(&s);
                    printf("Moved back from page %d\n", removed);
                }
                break;

            case 3:
                display(&s);
                break;

            case 4:
                n = 0;
                break;

            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
