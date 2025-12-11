#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

void init_stack(stack *ps);
void push(int data, stack *ps);
int pop(stack *ps);
int peek(stack *ps);
int stack_full(stack *ps);
int stack_empty(stack *ps);

int main()
{
    stack S;
    init_stack(&S);

    int choice;

    do{
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Peek\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                exit(0);

            case 1:
                if(stack_full(&S))
                    printf("Stack is Full!\n");
                else {
                    int data;
                    printf("Enter data to push:");
                    scanf("%d",&data);
                    push(data,&S);
                    printf("Pushed = %d\n",data);
                }
                break;

            case 2:
                if(stack_empty(&S))
                    printf("Stack is Empty!\n");
                else {
                    int val = pop(&S);
                    printf("Popped = %d\n",val);
                }
                break;

            case 3:
                if(stack_empty(&S))
                    printf("Stack Empty! Peek not possible.\n");
                else
                    printf("Top element = %d\n",peek(&S));
                break;

            default:
                printf("Invalid choice.\n");
        }

    }while(choice != 0);

    return 0;
}

void init_stack(stack *ps)
{
    ps->top = SIZE;   // descending stack
}

void push(int data, stack *ps)
{
    ps->top--;                 // move top downward
    ps->arr[ps->top] = data;   // store value
}

int pop(stack *ps)
{
    int val = ps->arr[ps->top];
    ps->top++;                 // move top upward
    return val;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}

int stack_full(stack *ps)
{
    return (ps->top == 0);     // no space above
}

int stack_empty(stack *ps)
{
    return (ps->top == SIZE);  // top is at initial position
}
