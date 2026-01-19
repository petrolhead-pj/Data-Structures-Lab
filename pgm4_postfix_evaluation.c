#include<stdio.h>
#include<ctype.h>

#define SIZE 50

int stack[SIZE];            //!not char stack
int top=-1;
void push(int val){              
    if(top==SIZE-1) printf("Stack overflow");
    else stack[++top]=val;
}

int pop(){          //! here int pop,as in this pgm we are just dealing with integers no characters! We only push int here not any characters
    if(top==-1) return -1;
    else return stack[top--];
}


//*Whenever you see an operand, push it to the stack.
//*Whenever you see an operator, pop the top two elements, perform the operation, then push the result back.

int eval_postfix(char exp[]){
    int i;
    char ch;
    int op1,op2,result;

    for(i=0;exp[i]!='\0';i++){
        ch=exp[i];
        if(isdigit(ch)) push(ch-'0');         //if the current character is a digit, then push the integer value of that character
                                              //we want integer values only, to convert '5' to 5, we subract by '0'. ASCII value of 0 is 48, 1 is 49 and so on
                                              //EG:if ch='5', then '5'-'0'= 53-48= 5 (converted to integer and now this gets pushed)

        else{
            op1=pop();
            op2=pop();
            switch(ch){                     //<>Now operand(digit) hai nhi(checked in if) to it would be an operator for sure,so ch variable has an operator
                case '+': result= op2+op1;  
                          break;
                case '-': result= op2-op1;
                         break;
                case '*': result = op2 * op1; 
                         break;
                case '/': result = op2 / op1;
                          break;
                default: printf("Invalid operator");
                        return -1;
            }

            push(result);     //whatever is the result push it in the stack
        }

    }
    //for loop ended now and all evaluation is completed
    return pop();       //!At last, only one element will be there in the stack after all the evaluation, which would be the final result. so pop out that last eleemnt which is the ans
                
}

int main(){
    char postfix[SIZE];
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);

    int result=eval_postfix(postfix);
    printf("%d",result);

    return 0;
}
