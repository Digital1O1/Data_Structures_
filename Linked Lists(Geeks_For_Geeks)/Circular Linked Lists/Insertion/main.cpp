#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *addToEmpty(Node *tail, int data)
{
    // This function is only for empty list
    if (tail != NULL)
        return tail;

    // Creating a node dynamically.
    Node *new_node = new Node();

    // Assigning the data.
    new_node->data = data;

    // Update tail pointer to point towards new_node
    tail = new_node;

    // Creating the link that loops around to the first node
    tail->next = tail;
    return tail;
}

Node *addBegin(Node *tail, int data)
{
    if (tail == NULL)
        return addToEmpty(tail, data);

    // Allocate space for the new node
    Node *new_node = new Node();
    // Insert the incoming data
    new_node->data = data;
    // Create link with incoming node to the previous/tail node
    new_node->next = tail->next;
    // Have the tail node point to the new inserted node
    tail->next = new_node;
    return tail;
}

Node *addEnd(Node *tail, int data)
{
    // Reference : https://www.youtube.com/watch?v=kErHUGvFrNg&ab_channel=NesoAcademy
    if (tail == NULL)
        return addToEmpty(tail, data);

    Node *newP = new Node();

    // Insert new data
    newP->data = data;

    // The swiggly lines are where the pointers are pointing
    // Have the inserted/new_node node point towards the first node in the list
    // It's worth noting that the pointer(s) to newP and tail 'switch'
    newP->next = tail->next;

    // Have the previous node before the inserted node point towards the inserted node
    // Have the tail node point to the new inserted node

    // Have the former 'last' node point to the newP node that's now the last node of the list
    tail->next = newP;

    // Have the tail pointer (that was formerly 2nd to last) point towards the newP node
    tail = newP;

    return tail;
}

Node *addAfter(Node *tail, int data, int item)
{
    if (tail == NULL)
        return NULL;

    struct Node *new_node, *traversing_node;

    // traversing_node points towards the 'front' of the LL
    traversing_node = tail->next;

    do
    {
        // If the item is found
        if (traversing_node->data == item)
        {
            // Create a new node
            Node *new_node = new Node();

            // Have the newly created node store the data
            new_node->data = data;

            // Have the new_node point and 'skip' the node that traversing_node is currently pointing towards
            new_node->next = traversing_node->next;

            // Have traversing_node point towards new_node
            traversing_node->next = new_node;
            if (traversing_node == tail)
                tail = new_node;
            return tail;
        }

        // Update the traversing_node to point towards the new_node
        traversing_node = traversing_node->next;
    } while (traversing_node != tail->next);

    cout << item << " not present in the list." << endl;
    return tail;
}

void traverse(struct Node *tail)
{
    struct Node *p;

    // If list is empty, return.
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Pointing to first Node of the list.
    p = tail->next;

    // Traversing the list.
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != tail->next);
}

// Driver code
int main()
{
    struct Node *tail = NULL;
    tail = addToEmpty(tail, 6);
    tail = addBegin(tail, 4);
    tail = addBegin(tail, 2);
    tail = addEnd(tail, 8);
    // tail = addEnd(tail, 12);
    // tail = addAfter(tail, 10, 8);

    // Function call
    traverse(tail);
    return 0;
}
