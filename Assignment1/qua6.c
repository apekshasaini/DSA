#include<stdio.h>
#define SIZE 7

int comparisons;

int find_rank(int arr[SIZE], int key);

int main()
{
    int arr[SIZE] = {10, 20, 15, 3, 4, 4, 1};

    int key;
    printf("Enter the element to find rank: ");
    scanf("%d", &key);

    int rank = find_rank(arr, key);

    if(rank == 0)
        printf("Element not found in stream\n");
    else
        printf("Rank of %d is: %d\n", key, rank);

    printf("Comparisons = %d\n", comparisons);

    return 0;
}

int find_rank(int arr[SIZE], int key)
{
    int count = 0;

    for(int i = 0; i < SIZE; i++)
    {
        comparisons++;
        if(arr[i] <= key)
        {
            count++;
        }
    }

    return count;
}
