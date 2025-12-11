#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node* create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_pos(int data,int pos);
int count_nodes();
void delete_first();

void display_reverse(struct node *trav)
{
    if(trav == NULL)
        return;

    display_reverse(trav->next);
    printf("->%d", trav->data);
}
// ------------------------------

int main()
{
    add_first(10);
    add_first(20);
    add_first(15);
    add_first(25);
    printf("\n Add First :\n");
    display();

    add_last(50);
    add_last(80);
    add_last(75);
    printf("\n Add Last :\n");
    display();

    add_at_pos(90,5);
    printf("\n Add at pos :\n");
    display();

    delete_first();
    printf("\n Delete First Node :\n");
    display();

    printf("\n Reverse Display:\nHead");
    display_reverse(head);
    printf("\n");

    return 0;
}

struct node* create_node()
{
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void add_first(int data)
{
   struct node* ptr = create_node();
   ptr->data = data;

   if(head == NULL)
    head = ptr;
   else
   {
    ptr->next = head;
    head = ptr;
   }
}

void display()
{
    if(head == NULL)
        printf("Linked List is Empty !\n");
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void add_last(int data)
{
    struct node *ptr = create_node();
    ptr->data = data;

    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void add_at_pos(int data,int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            add_first(data);
        else
            printf("Invalid pos number !\n");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes()+1)
        printf("Invalid pos number !\n");
    else
    {
        struct node *ptr = create_node();
        ptr->data = data;

        struct node *trav = head;
        for(int i =1; i< pos-1; i++)
            trav = trav->next;

        ptr->next = trav->next;
        trav->next = ptr;
    }
}

int count_nodes()
{
    int count = 0;
    struct node *trav = head;

    while(trav != NULL)
    {
        count++;
        trav = trav->next;
    }

    return count;
}

void delete_first()
{
    if(head== NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;

        free(temp);
        temp = NULL;
    }
}
