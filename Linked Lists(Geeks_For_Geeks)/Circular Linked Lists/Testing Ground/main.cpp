#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void add_To_Empty(Node **tail_reference, int incoming_value)
{
    Node *new_node = new Node();
    new_node->data = incoming_value;

    // Create a circular link where the node points back to itself
    new_node->next = new_node;

    // Update 'tail_reference' to point to the newly created node
    // Making it the new 'tail' node of the circular linked list
    *tail_reference = new_node;
}

void add_To_List(Node **tail_reference, int incoming_value)
{
    // Create space for new node
    Node *new_node = new Node();

    // Point new_node towards incoming pointer and value
    new_node->data = incoming_value;
    new_node->next = *tail_reference;

    // Also have last_node point towards incoming pointer
    Node *traversing_node = *tail_reference;

    // Traverse through LL with last_node
    // Since we're not going to NULL as with singly LL, we're heading towards the first node in the LL
    while (traversing_node->next != *tail_reference)
        traversing_node = traversing_node->next;

    // After traversing_node points towards head
    // update traversing_node pointer to point towards new_node to
    // complete circular linking of new node to the LL
    traversing_node->next = new_node;
}

void add_End(Node **last_node, int incoming_value)
{
    // Create a new node and set its data
    Node *temp = new Node();
    temp->data = incoming_value;

    // Point the new node's 'next' to the current first node (forming circular link)
    temp->next = (*last_node)->next;

    // Update the 'next' pointer of the previous last node to point to the new node
    (*last_node)->next = temp;

    // Update the 'last_node' pointer to point to the new last node
    // No actual 'link' is made, we're just moving the pointers are this point
    *last_node = temp;
}

void print_Nodes(Node *tail_reference)
{
    if (tail_reference == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = tail_reference;

    // Since we're dealing with CIRCULAR linked lists and not Singly LL
    // The tail_reference is the NULL since there's technically no 'end' with a circular LL
    do
    {
        printf("%d ", temp->data);
        // cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail_reference);

    cout << endl;
}

void deleteFirstNode(Node **tail)
{
    if (*tail == nullptr)
    {
        printf("LIST EMPTY\r\n");
        return; // No need to proceed further if the list is empty
    }

    Node *firstNode = (*tail)->next; // Get the first node (next of tail)

    if (firstNode == *tail)
    {
        // If there's only one node in the list, delete it and set tail to nullptr
        delete firstNode;
        *tail = nullptr;
    }
    else
    {
        // Update the tail's next pointer to skip the first node
        (*tail)->next = firstNode->next;

        // Delete the first node
        delete firstNode;
    }
}

using namespace std;

int main()
{
    // Node node;        // WRONG
    Node *node = NULL;
    add_To_Empty(&node, 2);

    add_To_List(&node, 11);
    add_To_List(&node, 23);
    add_To_List(&node, 44);
    add_End(&node, 23388);
    print_Nodes(node);

    return 0;
}
