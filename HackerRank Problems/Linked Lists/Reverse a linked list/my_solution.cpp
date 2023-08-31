#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insertNode(Node **head, int new_data)
{
    // Allocate new node
    Node *new_node = new Node();

    // Have new node point towards current head node
    new_node->next = (*head);

    // Set incoming data into new node
    new_node->data = new_data;

    // Have current head pointer point to new_node
    (*head) = new_node;
}
void printNodes(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\r\n");
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
int main()
{
    Node *head = NULL;

    insertNode(&head, 7);
    insertNode(&head, 13);
    insertNode(&head, 16);
    // insertNode(&head, 51);

    // for (int i = 0; i < 5; i++)
    // {
    //     insertNode(head, i);
    // }
    // printNodes(head);
    printNodes(head);

    insertNode(head, 1, 2);
    printNodes(head);

    return 0;
}