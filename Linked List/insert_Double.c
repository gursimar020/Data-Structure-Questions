//Inserting a Node Into a Sorted Doubly Linked List


/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    if(head == NULL) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = data;
        return node;
    }

    if(head->data <= data) {
        head->next = SortedInsert(head->next, data);
        head->next->prev = head;
    }
    else if(head->data > data)
    {
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = data;

        node->next = head;
        node->prev = head->prev;

        head->prev = node;
        head = node;
    }

    return head;
}
