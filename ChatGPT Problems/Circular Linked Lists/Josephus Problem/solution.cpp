#include <iostream>
#include <cstdint>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *addToEmpty(int data)
{
    Node *new_node = new Node(data);
    new_node->next = new_node;
    return new_node;
}

Node *addNode(Node *tail, int data)
{
    if (tail == nullptr)
        return addToEmpty(data);

    Node *new_node = new Node(data);
    new_node->next = tail->next;
    tail->next = new_node;
    return new_node; // new node becomes the new tail
}

int josephus(Node *tail, int stepCount)
{
    // Keeps iterating until there's only one node left
    while (tail != tail->next)
    {
        // Moves the tail pointer to the node JUST BEFORE the one is to be deleted
        // It stops 'early' since it only occurs on the next node : tail->next
        for (int i = 1; i < stepCount; ++i)
        {
            tail = tail->next;
        }

        // This actually moves to the node that needs to be deleted
        Node *toDelete = tail->next;

        /*
             'Removes' the toDelete node from the circular LL

             This is done by updating the 'next' pointer of tail to SKIP the 'toDelete' node and point to the next node in the sequence

             Visualization before deletion for tail->next = toDelete->next;

             tail
                ↓
                A → B → C → D → ...
                    ↑
                toDelete

            Visualization after deletion

            tail        toDelete
            ↓            ↓
            A -----> C → D → ...
        */
        tail->next = toDelete->next;
        delete toDelete;
    }
    int survivingPosition = tail->data;
    delete tail; // Cleaning up the last node
    return survivingPosition;
}

int main()
{
    int numberOfPeople = 10;
    int stepCount = 3;

    Node *tail = nullptr;
    for (int i = 1; i <= numberOfPeople; i++)
    {
        tail = addNode(tail, i);
    }

    int safePosition = josephus(tail, stepCount);
    cout << "The safe position is: " << safePosition << endl;

    return 0;
}
