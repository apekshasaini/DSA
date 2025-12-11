#include<stdio.h>
#define SIZE 9
int binary_search(int arr[SIZE],int key);
int rec_binary_search(int arr[SIZE],int key,int left,int right);
int main()
{
    // Descending sorted array
    int arr[SIZE] = {99,88,77,66,55,44,33,22,11};

    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);

    int index = binary_search(arr,key);
    if(index == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at index %d\n",index);

    printf("\n Recursive Function call :\n ");
        
    int res = rec_binary_search(arr,key,0,SIZE-1);
    if(res == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at index %d\n",res);

    return 0;
}

int binary_search(int arr[SIZE],int key)
{
    int left = 0, right = SIZE-1, mid;

    while(left <= right)
    {
        mid = (left+right) / 2;

        if(key == arr[mid])
            return mid;

        // descending order
        if(key > arr[mid])
        {
            right = mid - 1;   // move left
        }
        else
        {
            left = mid + 1;    // move right
        }
    }
    return -1;
}

int rec_binary_search(int arr[SIZE],int key,int left,int right)
{
    if(left > right)
        return -1;

    int mid = (left+right)/2;

    if(key == arr[mid])
        return mid;

    // CHANGED logic for descending order
    if(key > arr[mid])
    {
        return rec_binary_search(arr, key, left, mid-1);
    }
    else
    {
        return rec_binary_search(arr, key, mid+1, right);
    }
}
