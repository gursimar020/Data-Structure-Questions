//Get Node Value



/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    int index = 0;
    Node* current = head;
    Node* result = head;
    while(current!=NULL)
    {
        current=current->next;
        if (index++>positionFromTail)
        {
            result=result->next;
        }
    }
    return result->data;
}
