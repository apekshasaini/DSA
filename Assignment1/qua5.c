#include<stdio.h>
#define SIZE 11

int comparisons;

int linear_search(int arr[SIZE]); 

int main()
{
    int arr[SIZE] = {1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8};

    int result = linear_search(arr);

    if(result == -1)
        printf("No non-repeating element found!\n");
    else
        printf("First non-repeating element is %d\n", result);

    printf("Comparisons = %d\n", comparisons);

    return 0;
}

int linear_search(int arr[SIZE])
{
    // Traverse each element
    for(int i = 0; i < SIZE; i++)
    {
        int count = 0;

        // Compare with every element
        for(int j = 0; j < SIZE; j++)
        {
            comparisons++;
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        // If element appears only once
        if(count == 1)
        {
            return arr[i];   // return value, not index
        }
    }

    return -1;  // no non-repeating element
}
