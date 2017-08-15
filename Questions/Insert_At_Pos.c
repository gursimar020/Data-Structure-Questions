//Insert a node at a specific position in a linked list

/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  Node* temp=new Node;
    temp->data=data;
    if(position==0)
  {

      temp->next=head;
      head=temp;
  }

  else
  {
      Node* c=new Node;
      int count=1;
      c=head;
      while(count!=position)
      {
          c=c->next;
          count++;
      }
      temp->next=c->next;
      c->next=temp;

  }
 return head;   
}