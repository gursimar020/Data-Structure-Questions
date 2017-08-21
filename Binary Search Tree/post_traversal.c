//Tree: Postorder Traversal

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void postOrder(node *root) {
if(root==NULL) return;
    if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
    printf("%d ",root->data);
    
}
}
