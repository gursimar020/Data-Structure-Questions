//Delete duplicate-value nodes from a sorted linked list


/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    Node *temp,*next;
    temp=head;
    while(temp->next!=NULL){
        
        if(temp->next!=NULL){
            next=temp->next;
            if(temp->data==next->data){
                temp->next=next->next;
            }
            else
                temp=temp->next;
        }
        
    }
    return head;
}