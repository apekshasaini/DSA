#include<stdio.h>
#define SIZE 9

int comparisons;

int linear_search(int arr[SIZE],int key, int n);   // modified prototype

int main()
{
    // Example array with duplicate elements
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    
    // 1. Get the key from the user.
    int key, n;
    printf("Enter the key to search :");
    scanf("%d",&key);

    printf("Enter the occurrence number (n): ");
    scanf("%d",&n);

    int index = linear_search(arr,key,n); // modified function call
    if(index == -1)
        printf("Key Not Found !\n");
    else
        printf("Key found at index %d\n",index);
        
    printf("Comparisons = %d\n",comparisons);

    return 0;
}

int linear_search(int arr[SIZE],int key, int n) // modified function
{
    int count = 0;

    //2. Start the traversal from the 1st element of the array(0th Index).
    for(int index = 0; index < SIZE; index++)
    {
        // 3. Compare the key to search with each element of the array.
        comparisons++;
        if(key == arr[index])
        {
            count++;
            if(count == n)
            {
                // If nth occurrence found, return index
                return index;
            }
        }
        // Else, continue the search till the last index of the array.
    }
    return -1; // nth occurrence not found
}
