#include <iostream>

using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;
};

/*
    Given a reference (pointer to pointer)
    to the head of a list and an int, inserts
    a new node on the front of the list.
*/
void push(Node **head_ref, int new_data)
{
    /* 1. allocate node */
    Node *new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node *prev_node, int new_data)
{
    /* References
        https://www.youtube.com/watch?v=zK-qTBWozcY&ab_channel=CodeVault
        https://www.youtube.com/watch?v=g8VLr7UGsZo&ab_channel=ArpanPathak
        https://www.youtube.com/watch?v=0hGxILnKvJk&ab_channel=NesoAcademy
    */
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    Node *new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    // Remember : next is the pointer variable
    // Connect prev_node to new_node
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node **head_ref, int new_data)
{
    /* 1. allocate node */
    Node *new_node = new Node();

    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    /*
        Have the last node point towards the new_node that's already pointing towards NULL
    */
    last->next = new_node;
    return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

int look_for(Node *node, int key)
{
    while (node != NULL)
    {
        if (node->data != key)
        {
            node = node->next;
        }
        else
        {
            // printf("MATCH FOUND : %d with %d \r\n", node->data, key);
            
            // Don't put return statement here or else you'll get the following warning
            // my_attemp.cpp:130:1: warning: control reaches end of non-void function [-Wreturn-type]
            // return node->data; 
            break;
        }
    }

    // Correct place to put return statement
    return node->data;
}
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    // cout << "Created Linked list is: ";
    // printList(head);

    int searched_value = 4;
    printf("Searching for %d \r\n", searched_value);

    int answer = look_for(head, searched_value);
    printf("Answer : %d \r\n", answer);
    return 0;
}