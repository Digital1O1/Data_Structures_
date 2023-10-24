ListNode *removeElements(ListNode *head, int val)
{
    // Checks if head isn't null and if the node isn't the value we're looking for
    while (head && (head->val == val))
    {
        // Create new node called tempNode
        ListNode *tempNode = head;
        // Have head node advance one more spot
        // Pretty much removes teh current head node from the list
        head = head->next;
        // Delete the tempNode
        delete tempNode;
    }

    ListNode *prev = head, *current = head;

    // Loop iterates through list as long as current isn't NULL
    while (current)
    {
        // If the value is found
        if (current->val == val)
        {
            // Store the current node in tempNode
            ListNode *tempNode = current;

            // Have prev node to skip one node ahead where current node is at
            /*
                Lets say we want to delete : 4
                And the list is : [    1    ,    2     ,    4    ,    2    ]
                                              prev         current
                                                           tempNode

                After :  prev->next = current->next;

                And the list is : [    1    ,    2     ,    4    ,    2    ]
                                                           tempNode  prev
                                                                    current

            */
            prev->next = current->next;

            // Have the current pointer moved to the next node
            current = current->next;
            delete tempNode;
        }

        // If we haven't found the value yet
        else
        {
            // Update the prev node to where current is at
            prev = current;

            // Advance the current pointer forward
            current = current->next;
        }
    }
    return head;
}
