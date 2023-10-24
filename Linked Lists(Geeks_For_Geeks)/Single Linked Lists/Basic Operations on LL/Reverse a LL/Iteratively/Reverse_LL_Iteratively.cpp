// Reference link : https://www.geeksforgeeks.org/reverse-a-linked-list/?ref=lbp

#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        /*

        How to reverse a LL

            1) Initialize three pointers
                - prev as NULL
                - current as HEAD
                - next as NULL
            2) Iterate through LL using a loop and do the following
                - Store the NEXT node
                    - next = current -> next
                - Update the NEXT pointer of CURRENT to the PREV
                    - current -> next = prev
                - Update
                    1) prev as current
                    2) current as next
                    - prev = current
                    - current = next

        NOTE : Which ever side th arrow is on cooresponds to the pointer's direction
        */
        // Initialize current, previous and next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            // Store the 'current' next pointer in next
            next = current->next;

            // Reverse current node's pointer
            // Does the actual pointer reversal
            // Move the pointer that's associated with CURRENT to where PREV is at
            current->next = prev;

            // Move pointers one position ahead.
            // Move PREV to CURRENT
            prev = current;
            // Move CURRENT to NEXT
            current = next;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(2);
    ll.push(1);
    // ll.push(3);
    // ll.push(4);
    // ll.push(5);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}
