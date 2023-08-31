# [Linked Lists and Double Pointers](https://stackoverflow.com/questions/7271647/what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-lis)

## Why Use Double Pointers

### - Lets you change the head pointer directly versus returning the new one

### - If not you have to return the new head and the function call is responsible for updating itself

<br>

# Example(s)

## WITH double pointer 

```C++
// note that there's no return value: it's not needed
void push(struct node** head, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head = newnode; // *head stores the newnode in the head
}

// and call like this:
push(&head,1);
```

## WITHOUT double pointer

```C++
struct node* push(struct node* head, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    return newnode;
}

/*
    note the assignment of the result to the head pointer
        - If you don't, you'll leak the nodes you allocate with malloc
        - And the head pointer will ALWAYS point to the same node
*/

// This is the assignement mentioned
head = push(head,1);
```

<br>

# [Quora : Why double pointers used in Linked Lists](https://www.quora.com/Why-double-pointers-are-used-in-linked-list)

## Double pointers

### Used when functions need to modify head of the linked list (update the list) w/o needing to return the head

### Single pointers used in functions that modify the head of a linked list NEED to return the head

<br>

## Simple-C rule

>“if you want to modify local variable of one function inside another function, pass pointer to that variable.”

# Example 1 : Swap function

```C++
void swap1(int* a ,int* b){ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
/* 
    If you change 'void swap1(int* a ,int* b)' --> void swap1(int a ,int b)
    Nothing will happen, hence the importance of using a pointer
*/ 
```