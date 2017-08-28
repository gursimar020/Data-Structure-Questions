//Cycle Detection in linked list.


/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
bool has_cycle(Node* head) {
    
    Node *slow = head;//slow pointer
    Node *fast = head;//fast pointer
    bool cycle = false;
    while(fast != NULL)
    {
        slow = slow->next; // goes slower
        fast = fast->next->next; // goes faster
        
        
        if(slow == fast) // if they meet => cycle.. easy
            {
            cycle = true;
            break;
        }
        
        
    }
    return cycle;
  
}