# [Deleting a node](https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/?ref=lbp)

## You can delete a element from a list from the :

### 1) Beginning

### 2) End

### 3) Middle

<br>

---

<br>

## 1. Delete from Beginning:

```cpp
Point head to the next node i.e. second node
    temp = head

    // Move head node to 2nd node in Linked List 
    head = head->next

Make sure to free unused memory
    free(temp); or delete temp;
```

<br>

## 2. Delete from end:

```cpp
    Point head to the previous element i.e. last second element
    Change next pointer to null

    Node *second_last = *head;

    // If list is already empty
    if (head == NULL)
        printf("LIST IS EMPTY\r\n");
    // return NULL;

    // If you're already at the end of the list
    if (second_last->next == NULL)
    {
        delete head;
        // return NULL;
    }

    // Keeo looping until you hit NULL
    while (second_last->next)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = NULL;
```

<br>

## 3.Delete from Middle:

```cpp
Keeps track of pointer before node to delete and pointer to node to delete
    struct node *temp = head;
    struct node *prev = head;
    for(int i = 0; i < position; i++)
    {
        // If the node is at the start of the LL
        if(i == 0 && position == 1)
        {
            head = head->next;
            free(temp)
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if(prev == NULL) // position was greater than number of nodes in the list
                    break;
                temp = temp->next;
            }
        }
    }
```

## Bonus : Deleting the Node at a Particular Postiion

### [Reference link](https://www.youtube.com/watch?v=f1r_jxCyOl0&ab_channel=NesoAcademy)

```cpp
void delete_node_at_pos(Node **head, int position)
{

    // Points to the node RIGHT before the one we're going to delete
    Node *previous = *head;

    // This node will point to whatever we want to delete
    Node *current = *head;

    // Check if LL is empty
    if (*head == NULL)
    {
        printf("Linked List is EMPTY \r\n");
    }

    // If the user wants to delete the first node of the list
    else if (position == 1)
    {
        // Move head pointer to next node in list
        *head = current->next;

        // Delete the node in the first position
        free(current);
        // This has to be done or you'll lose the link and the entire linked list
        current = NULL;
    }
    else
    {
        // This will iterate through the linked list
        while (position != 1)
        {
            // move current pointer to where previous pointer is at
            // update previous pointer to where current pointer is at
            previous = current;

            // move the pointer to the next node
            current = current->next;
            position--;
        }
        // When position == 1, delete that node
        // This will take the previous node and point 'over' the node that's about to get deleted
        // Check reference #3 below
        previous->next = current->next;
        free(current);
        current = NULL;
    }

    /*
        If there were three nodes, node A/B/C

        If we wanted to update the previous node to point to the node AFTER the one we're about to delete,
        it would look something like this

        previous->next = current->next
    */
}
```

![image](https://user-images.githubusercontent.com/39348633/217406381-098d9dd4-c9ce-478b-bc3f-99fb76f6feee.png)

<br>

# Iterative Method

## To delete a node from a Linked List, we have to do the following:

### 1) Find the previous node of the node to be deleted.

### 2) Change the next of the previous node.

### 3) Free memory for the node to be deleted.

<br>

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/05/Linkedlist_deletion.png)

## Reference #3

![image](https://user-images.githubusercontent.com/39348633/228387668-d64fbd2e-51f5-4875-b0da-c11ff808bf4a.png)
