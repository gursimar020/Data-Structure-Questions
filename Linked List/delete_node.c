//Delete a Node from linked list

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
       Node* temp = head;
     
     int i;

        if(position == 0){
            head = head->next; //move from head (1st node) to second node
        }else{
            for(i = 1; i < position; ++i){ //move through list
                    temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    
    return head;
}
