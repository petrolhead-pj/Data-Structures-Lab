#include<stdio.h>
#include<ctype.h>
#define SIZE 50

char stack [SIZE];
int top=-1;

void push(char ch){
    if(top==SIZE-1) printf("Stack on overflow");
    else stack[++top]=ch;
}

char pop(){
    if(top==-1) return -1;
    else return stack[top--];
}

int precedence(char symbol){
    switch (symbol){
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infix_postfix ( char infix []){
    char postfix[SIZE];              //final ans will be stored in this variable
    int i,j=0;                          // i for scanning infix and j for putting data in postfix
    char ch,temp;

    for(i=0;infix[i]!='\0'; i++){
        ch=infix[i];
        if(isalnum(ch)){          //isalnum is a defined function in <ctype.h> which cheks whether the givenn character is an operand( A-Z or a-z or 0-9)
            postfix[j++]=ch;        //if operand then directly add krdo postfic expression me
        }

        else{                          
            if(ch=='(') push(ch);                       //parenthesis hua agr to
            else if(ch==')'){
                while( (temp=pop()) !='(' )             //temp=pop() removes the top element of the stack and then we check whehter that element is equal to open parenthesis or not
                    postfix[j++]=temp;     
            }
    

        //<> Now, we have checked for whether the character is an operand and both brackets(), now it must be an operator
            else {
                while( top!=-1 && precedence(stack[top]) > precedence(ch) ){       //Stack should never be empty and push operators in stack until curOperator has higher precedence than top element in stack and also if stack is empty we can't pop anything so top!=-1
                    postfix[j++]=pop();            //pop and store the element in the postfix
                }
                push(ch);                       //now push the current Operator
            }
        }
    }

    //<> if some operators are still left in the stack and the symbols are over, push all those elements into the postfix until the stack is empty
     while(top!=-1){
        postfix[j++]=pop();            //pops the top operator of the stack and append it in postfix
     }

     postfix[j]='\0';                //Adds a null terminator \0 at the current end of the postfix string to mark the end of the string so that printf knows where it ends
     printf("The postfix expression is %s",postfix);
}

int main(){
    char infix[SIZE];
    printf("Enter the infix expression ");
    scanf("%s",infix);

    infix_postfix(infix);

    return 0;
}
