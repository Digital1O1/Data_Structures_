// Iterative C++ program to find length
// or count of nodes in a linked list
#include <iostream>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Counts no. of nodes in linked list */
int getCount(Node *head)
{
    int count = 0;        // Initialize count
    Node *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    /* Use push() to construct below list
    1->2->1->3->1 */
    push(&head, 1);
    push(&head, 3);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);

    // Function call
    printList(head);

    cout << endl;
    return 0;
}
