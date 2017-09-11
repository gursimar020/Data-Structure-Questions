//top view of binary tree


/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

    void left_view(node* root)
{
    if(!root) return;
    left_view(root->left);
    cout << root->data << " ";
}

void right_view(node* root)
{
    if(!root) return;
    cout << root->data << " ";
    right_view(root->right);
}

void topView(node * root)
{
    left_view(root->left);
    cout << root->data << " ";
    right_view(root->right);
}
