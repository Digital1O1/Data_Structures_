#include <iostream>
#include <cstdint>
using namespace std;

class Node
{
public:
    int data;
    /*
        Notes about Node*next
            - Node : is the type that represents the structure of the class
                - Node* tells the compiler what type of data the pointer will be pointing to
                - It's not just pointing to any address, but where the 'Node' object is stored
            - next : just the name of the variable
    */
    Node *next;

    // Constructor that initializes data and sets next to nullptr
    Node(int val) : data(val), next(nullptr) {}

    /*
        Reasons why to use the constructor
            - Initialization clarity/safety
                - The constructor explicitly initializes the 'Node' object's data/pointers
                - Without one the class
    */
};

Node *addToEmpty(Node *tail, int data)
{
    if (tail != nullptr)
        return tail;

    Node *new_node = new Node(data);
    tail = new_node;
    tail->next = tail;
    return tail;
}

Node *addNode(Node *tail, int data)
{
    if (tail == nullptr)
        return addToEmpty(tail, data);

    Node *new_node = new Node(data);
    new_node->next = tail->next;
    tail->next = new_node;
    return new_node; // new node becomes the new tail
}
void traverse(Node *tail)
{
    Node *p;

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

/*
    ChatGPT prompt

    The Josephus Problem:

    This is a famous theoretical problem that originates from a historical context but has since been abstracted into a mathematical puzzle. The problem is formulated as follows:

    There are n people standing in a circle waiting to be executed.
    Starting from a specified point in the circle, a designated "executioner" skips m-1 people and executes the mth person.
    The process is repeated with the remaining people, starting with the next person, going in the same direction and skipping m-1 people, and executing the mth person.
    This continues until only one person is left, who is then freed or spared.
    The challenge is to choose a place in the initial circle so that you are the last remaining person.


    Game plan
    - Initalize the circular linked list
    - Traverse the created linked list
        - Have the executioner go to the stepCount and -1
*/

int main()
{
    // Node tail;
    Node *tail = NULL;
    int numberOfPeople = 10;
    int stepCount = 2;
    int startingPoint = 0;
    int numberOfPeopleLeft = 0;
    // std::cout << "test" << std::endl;

    // Insert elements into circular LL
    printf("Elements in circular linked list : ");
    for (int initalizeNumberOfPeople = 1; initalizeNumberOfPeople <= numberOfPeople; initalizeNumberOfPeople++)
    {
        tail = addNode(tail, initalizeNumberOfPeople);
    }
    // traverse(tail);
    printf("\r\n");

    if (tail == nullptr)
    {
        printf("Only one survivor present \r\n");
    }
    Node *current = tail;     // Create a pointer to the current node, starting from the head
    Node *previous = nullptr; // Create a pointer to the previous node, initially nullptr

    int positionCounter = 0;

    while (stepCount < positionCounter)
    {
        previous = current;      // Store the current node as the previous node
        current = current->next; // Move to the next node
        positionCounter++;

        // Check if we have cycled back to the head of the list while we're still traversing the list
        if (current == tail)
        {
            // std::cout << "Position " << position << " is out of bounds." << std::endl;
            return;
        }
    }

    // // Ensures pointer is pointing towards the first element in the list
    // tail = tail->next;

    // for (int traverseList = 0; traverseList <= stepCount - 1; traverseList++)
    // {
    //     printf("%d ", tail->data);
    //     tail = tail->next;
    // }

    return 0;
}