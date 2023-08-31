#include <iostream>

using namespace std;

class Node
{
public
    :
    int data;
    Node *next;
};

void add_node(Node **head, int value)
{
    // Allocate space for new node
    Node *new_node = new Node();

    // Insert new data into node
    new_node->data = value;

    // Make new node point towards head
    new_node->next = (*head);

    // 'Move' the new node
    (*head) = new_node;
}

void print_nodes(Node *head)
{
    while (head != NULL)
    {
        // print out data
        cout << head->data << " ";
        // 'move' head to get next value
        head = head->next;
    }
    cout << endl;
}

void insertAfter(Node *prev_node, int value)
{

    /*
            // 1. Check if the given prev_node is NULL
        if (prev_node == NULL) {
            cout << "The given previous node cannot be NULL";
            return;
        }

        // 2. Allocate new node
        Node* new_node = new Node();

        // Insert new_data into 'new_node'
        // 3. Put in the data
        new_node->data = new_data;

        // 4. Make next of new node as next of prev_node
        // This is the arrow that's going from B --> E
        new_node->next = prev_node->next;

        // 5. move the next of prev_node
        // as new_node
        prev_node->next = new_node;
    */

    // Node *prev_node = (head);
    // prev_node->data = value;

    Node *new_node = new Node();
    new_node->data = value;
    /*
        Example... There's three nodes
            - Node A
            - New Node
            - Node B

         new_node->next = prev_node->next;
            - This will make new_node point towards Node B
         prev_node->next = new_node;
            - New node will point to the new_node/new connection
    */
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main()
{
    Node *head = NULL;

    add_node(&head, 1); // (head) 1 --> NULL
    print_nodes(head);

    add_node(&head, 22); // (head) 22 --> 1 --> NULL
    print_nodes(head);

    add_node(&head, 192); // (head) 192 --> 22 --> 1 --> NULL
    print_nodes(head);

    insertAfter(head, 9999); // (head) 9999 --> 0 --> 22 --> 1
    print_nodes(head);
    insertAfter(head->next, 1324); // (head) 192 --> 9999 --> 1324 --> 22 --> 1
    print_nodes(head);

    return 0;
}