#include<stdio.h>
#define SIZE 9

int comparisons;

int linear_search(int arr[SIZE],int key); 

int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    
    // 1. Get the key from the user.
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);

    int index = linear_search(arr,key); // function call
    if(index == -1)
        printf("Key Not Found !\n");
    else
        printf("Key found at index %d\n",index);
        
    printf("Comparisons = %d\n",comparisons);

    return 0;
}

int linear_search(int arr[SIZE],int key)
{
    int lastIndex = -1; // store last occurrence

    // Traverse full array
    for(int index = 0; index < SIZE; index++)
    {
        comparisons++;

        if(key == arr[index])
        {
            lastIndex = index; // update last occurrence
        }
    }

    return lastIndex; // return last found index
}
