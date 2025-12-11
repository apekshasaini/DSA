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

// -------------------------------
// NEW FUNCTION (ONLY NECESSARY ADDITION)
// -------------------------------
void reverse_array(int arr[], int n)
{
    stack S;
    init_stack(&S);

    // push all elements
    for(int i = 0; i < n; i++)
        push(arr[i], &S);

    // pop back into array
    for(int i = 0; i < n; i++)
        arr[i] = pop(&S);
}
// -------------------------------

int main()
{
    // sample array
    int A[5] = {10, 20, 30, 40, 50};

    printf("Original Array:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", A[i]);
    printf("\n");

    // reverse using stack
    reverse_array(A, 5);

    printf("Reversed Array:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}

void init_stack(stack *ps)
{
    ps->top = SIZE;   // descending stack initialization
}

void push(int data, stack *ps)
{
    ps->top--;                // move top downward
    ps->arr[ps->top] = data;  // insert element
}

int pop(stack *ps)
{
    int val = ps->arr[ps->top];
    ps->top++;                // move top upward
    return val;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}

int stack_full(stack *ps)
{
    return (ps->top == 0);
}

int stack_empty(stack *ps)
{
    return (ps->top == SIZE);
}
