//height of tree 

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

int height(Node *root)
{
	if(root==NULL)
	return -1;
	
	int leftHeight=height(root->left);
	int rightHeight=height(root->right); 
	
	if(leftHeight>rightHeight)
	return leftHeight+1; 
	
	else 
	return rightHeight+1;
}
  