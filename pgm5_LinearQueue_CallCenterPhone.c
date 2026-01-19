#include<stdio.h>
#define SIZE 50

int Queue[SIZE];        //each number represents a phone call ID
int start = -1;
int end = -1;              //end or rear
int count = 0;             //curSize

int isEmpty(){
     return count == 0;
}

int isFull(){
    return count == SIZE;
}

//<> Add a new incoming call to the queue
void enqueue(int call){
    if(isFull())
        printf("Queue overflow: Call center is busy\n");     //overflow message
    else{
        if(start == -1) start = 0;        //<> if this is the first element of queue,then also increment queue value...we can also write if(isempty()) start=0;
        
        Queue[++end] = call;
        count++;
        printf("Call %d added to queue\n", call);
    }
}

//<> Remove a call when it is being serviced(means that call is handled by some agent and we have to remove it from the waiting line)
int dequeue(){
    if(count == 0){          //<>or simply if(isEmpty())
        printf("Queue underflow: No calls to service\n");
        return -1;
    }
    else{
        int deleted = Queue[start];
        start++;                             //! queue hai to delete hua element to start se hota and start age bdhta
        count--;
        if(count == 0) start = end = -1;    //<>  //reset the counter if the queue elements are empty otherwise queue will think elements are still there
        return deleted;
    }
}

//not req acc to q, for knowledge can read it's simple
// void display(){
//     if(isEmpty())
//         printf("No calls in queue\n");
//     else{
//         printf("Current call queue:\n");
//         for(int i = start; i <= end; i++){   //!
//             printf("Call ID: %d\n", Queue[i]);
//         }
//     }
// }

int main(){
    int callID;
    int choice;
    int n = 1;
    int a;      //for served calls/deletion store

    while(n){
        printf("\nEnter your choice\n");
        printf("1.Add Call  2.Service Call  3.Display Queue  4.Exit\n");
        scanf("%d",&choice);
        
        
        switch(choice){
            case 1:  printf("Enter Call ID: ");
                     scanf("%d",&callID);
                    enqueue(callID);
                     break;

            case 2: a = dequeue();
                    if(a != -1)  printf("Servicing Call ID: %d\n", a);
                    break;
            
            case 3:
                n = 0;
                break;

            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
