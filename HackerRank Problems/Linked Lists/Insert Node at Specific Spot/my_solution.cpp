// A complete working C++ program to
// demonstrate all insertion methods
// on Linked List
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node **head_ref, int new_data)
{
    // 1. allocate node
    Node *new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. move the head to point
    // to the new node
    (*head_ref) = new_node;
}

// Given a node prev_node, insert a new
// node after the given prev_node
void insertAfter(Node *prev_node, int new_data)
{
    // 1. check if the given prev_node
    // is NULL
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. allocate new node
    Node *new_node = new Node();

    // 3. put in the data
    new_node->data = new_data;

    // 4. Make next of new node
    // as next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// appends a new node at the end
void append(Node **head_ref, int new_data)
{

    // 1. allocate node
    Node *new_node = new Node();

    // used in step 5
    Node *last = *head_ref;

    // 2. put in the data
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
// ------------------------------------------- [ METHOD 1 ] ------------------------------------------- //
/*
void insert_at_location(Node *head_ref, int new_data, int position) // 1 7 6 4 --> 1 7 [2] 6 4 | Pos = 3
{
    // Reference : https://www.codingninjas.com/codestudio/library/insert-a-node-at-a-specific-position-in-a-linked-list
    // Allocate space for new node
    Node *temp1 = new Node();

    // Store user data and point it to nothing
    temp1->data = new_data;
    temp1->next = NULL;

    // function to insert node at position 1.
    if (position == 1)
    {
        temp1->next = head_ref;
        head_ref = temp1;
        return;
    }

    // inserting at the given position
    Node *temp2 = head_ref;

    // traversing
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }

    // updating the link
    temp1->next = temp2->next;
    temp2->next = temp1;
}
*/
// ------------------------------------------- [ METHOD 2 ] ------------------------------------------- //

Node *insert_at_location(Node *head_ref, int new_data, int position) // 1 7 6 4 --> 1 7 [2] 6 4 | Pos = 3
{
    Node *node = new Node();
    node->data = new_data;

    if (!head_ref)
        return node;

    Node *temp = head_ref;
    Node *previous_node;
    int count = 0;

    while (temp != nullptr)
    {
        if (count == position)
        {
            break;
        }
        previous_node = temp;
        temp = temp->next;
        count++;
    }

    previous_node->next = node;
    node->next = temp;

    return head_ref;
}

Node *insertNode(Node *head, int new_value, int position)
{
    // Reference link : https://www.youtube.com/watch?v=0hGxILnKvJk&t=332s&pp=ygUbaW5zZXJ0IG5vZGUgYXQgcG9zaXRpb24gQysr&ab_channel=NesoAcademy
    // Node *previous_node = new Node();

    // This node will traverse the LL
    Node *previous_node = head;
    Node *next_node = new Node(); 
    previous_node = head;
    next_node->data = new_value;

    for (int i = 0; i < position - 1; i++)
    {
        previous_node = previous_node->next;
    }
    // head = previous_node;

    // printf("\nValue to be inserted : %d at position : %d \r\n", new_value, position);
    // printf("New value %d \r\n", head->data);

    // Have next_node point towards the node that comes AFTER 
    next_node->next = previous_node->next;

    // Update 
    previous_node->next = next_node;

    head = next_node;

    return head;
}

// Driver code
int main()
{
    // Start with the empty list
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
    // insertAfter(head->next, 8);

    // Node | Data | Location
    insert_at_location(&*head, 0, 2);

    cout << "Created Linked list is: ";
    printList(head); // 1 7 6 4 --> 1 7 6 9 4

    return 0;
}
// This code is contributed by rathbhupendra, arkajyotibasak