//Find Merge Point of Two Lists


/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
   Node *A = headA;
    Node *B = headB;
   while(A != B)
   {
       A = A->next;
       B = B->next;
       
       if(A==NULL)
       A = headB;
        
       if(B==NULL)
       B = headA;
       
   }
   return A->data;
}