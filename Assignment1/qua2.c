#include<stdio.h>
#include<string.h>
#define SIZE 3

int comparisons;

struct Employee
{
    int empid;
    char name[20];
};

int linear_search(struct Employee arr[SIZE], int key, char str_key[], int search_by);

int main()
{
    struct Employee arr[SIZE] =
    {
        {101, "Ankita"},
        {102, "Abhijeet"},
        {103, "Pratiksha"}
    };
    
    int choice;
    printf("Search by:\n1. EmpID\n2. Name\nEnter choice: ");
    scanf("%d",&choice);

    int key = 0;
    char str_key[20] = {0};

    if(choice == 1)
    {
        printf("Enter EmpID to search: ");
        scanf("%d",&key);
    }
    else
    {
        printf("Enter Name to search: ");
        scanf("%s", str_key);
    }

    int index = linear_search(arr, key, str_key, choice);

    if(index == -1)
        printf("Employee Not Found!\n");
    else
        printf("Employee Found at index %d\n", index);

    printf("Comparisons = %d\n", comparisons);

    return 0;
}

int linear_search(struct Employee arr[SIZE], int key, char str_key[], int search_by)
{
    for(int index = 0; index < SIZE; index++)
    {
        comparisons++;

        if(search_by == 1)
        {
            if(key == arr[index].empid)
                return index;
        }
        else
        {
            if(strcmp(str_key, arr[index].name) == 0)
                return index;
        }
    }
    return -1;
}
