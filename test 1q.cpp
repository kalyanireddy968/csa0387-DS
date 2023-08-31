#include <stdio.h>   
void push();  
void pop();  
void peek();
int stack[50],i,j,option=0,n,top=-1;  
int main ()  
{  
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n);  
    printf("Stack implementation using array\n");  
    while(option != 4)  
    {  
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit");  
        printf("\n Enter your option \n");        
        scanf("%d",&option);  
        switch(option)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                peek();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid option");  
            }   
        };  
    }  
}   
void push ()  
{  
    int value;      
    if (top == n )   
    printf("\n Overflow");   
    else   
    {  
        printf("Enter the value?");  
        scanf("%d",&value);         
        top = top +1;   
        stack[top] = value;   
    }   
}   
void pop ()   
{   
    if(top == -1)   
    printf("Underflow");  
    else  
    top = top -1;   
}
void peek()  
{  
    for (i=top;i>=0;i--)  
    {  
        printf("%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack is empty");  
    }  
}  


