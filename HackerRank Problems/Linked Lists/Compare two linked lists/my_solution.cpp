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

void compare_lists(Node *head1, Node *head2)
{
    //Check initally if either node is NULL | If not, iterate through lists
    while (head1 != NULL && head2 != NULL)
    {
        // If values are different, break out of the loop
        if (head1->data != head2->data)
        {
            printf("ERROR\r\n");
            break;
        }

        // If they're the same, print out the values and keep 'iterating' through both lists
        printf("head1 : %d | head2 : %d \r\n", head1->data, head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }
}
// Driver code
int main()
{

    // Start with the empty list
    Node *head = NULL;
    Node *head2 = NULL;

    append(&head, 1);
    append(&head, 1);
    append(&head, 1);
    append(&head, 1);

    append(&head2, 1);
    append(&head2, 1);
    append(&head2, 1);
    append(&head2, 1);
    append(&head2, 1);

    // cout << "Created Linked list is: ";
    // printList(head);
    // cout << endl;
    // printList(head2);

    compare_lists(head, head2);
    return 0;
}
// This code is contributed by rathbhupendra, arkajyotibasak
