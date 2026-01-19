#include<stdio.h>
#define SIZE 50

int queue[SIZE];          //each number represents a process ID
int start = -1;
int end = -1;             //rear
int count = 0;            //or curSize

int isEmpty(){
      return count == 0;
}

int isFull(){
    return count == SIZE;
}

//<> Add a new process to the circular queue
void enqueue(int process){
    if(isFull())
        printf("Queue overflow: CPU scheduler is full\n");
    else{
        if(start == -1) start = 0;            //<> first process
        
        end = (end + 1) % SIZE;               //! circular increment
        queue[end] = process;
        count++;
        printf("Process added\n");
    }
}

//<> Remove a process when it gets CPU time
int dequeue(){
    if(isEmpty()){
        printf("Queue underflow: No process to schedule\n");
        return -1;
    }
    else{
        int deleted = queue[start];
        start = (start + 1) % SIZE;           
        count--;
        if(count == 0) start = end = -1;      //<> reset queue when empty otherwise queue will think elements are still there
        return deleted;
    }
}

void display(){
    if(isEmpty())
        printf("No processes in scheduler\n");
    else{
        printf("Processes in circular queue:\n");
        for(int i = 0; i < count; i++){           //yha pe count tk hi loop run as utne hi elements hoge and index apna position change krte hi ja rha
            int index = (start + i) % SIZE;       //circular traversal
            printf("Process ID: %d\n", queue[index]);
        }
    }
}

int main(){
    int processID;
    int choice;
    int n = 1;

    while(n){
        printf("\nEnter your choice\n");
        printf("1.Add Process  2.Schedule Process  3.Display Queue  4.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter Process ID: ");
                scanf("%d",&processID);
                enqueue(processID);
                break;

            case 2: {
                int a = dequeue();
                if(a!= -1)
                    printf("Process %d is being scheduled\n", a);
                break;
            }

            case 3:
                display();
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
