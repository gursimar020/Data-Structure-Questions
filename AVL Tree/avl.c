#include <stdio.h>

#include <stdlib.h>



typedef struct node

{

    struct node *left, *right;

    int height, data;

} node;







// utility function to create a node.

node* createNode(int data)

{

    node *myNode = (node *) malloc(sizeof(node));

    myNode -> left = myNode -> right = NULL;

    myNode -> height = 1;

    myNode -> data = data;

    return myNode;

}



// utility function to return height

int height(node* myNode)

{

    if (myNode == NULL) return 0;

    

    return myNode -> height;

}



// Balance factor.

int balanceFactor(node *myNode)

{

    if (!myNode) return 0;



    return height(myNode -> left) - height(myNode -> right);

}



// max funciton

int max(int a, int b)

{

    return (a > b ? a : b );

}



// utility function to rotate left

// applicable in R-R, R-L case. 

node* rotateLeft(node* myNode)

{

    printf("left rotation!!\n");

    node *child = myNode -> right;

    node *childLeft = child -> left;



// rotate here.

    child -> left = myNode;

    myNode -> right = childLeft;



// update heights.

// ensure the order in which heights are calculated very important!!!

// myNode height should be calculated first, as it affects the calculation

// of child's height.

    myNode -> height = 1 + max(height(myNode -> left), height(myNode -> right));

    child -> height = 1 + max(height(child -> left), height(child -> right));



    return child;

}



//applicable in L-L, L-R case.

node* rotateRight(node* myNode)

{

    printf("right rotation\n");

    node *child = myNode -> left;

    node *childRight =  child -> right;



// rotate right here.

    child -> right = myNode;

    myNode -> left = childRight;

    

    myNode -> height = 1 + max(height(myNode -> right), height(myNode -> left));

    child -> height = 1 + max(height(child -> right), height(child -> left));



    return child; 

}



//insert into AVL!!

node* insert(node* root, int data)

{

    //insert normally into bst

    if (root == NULL) return createNode(data);

    

    else if (data < root -> data) root -> left = insert(root -> left, data);



    else if (data > root -> data) root -> right = insert(root -> right, data);



    else    return root;



    root -> height = 1 + max(height(root -> left), height(root -> right));



    int balance = balanceFactor(root);

    

    // if you wanna know whats under the hood uncomment below.

    //printf("data : %d,  balance : %d, height : %d\n", root -> data ,balance, root -> height);

    // LL case.

    if (balance > 1 && data < root -> left -> data)

    {

        return rotateRight(root);

    }

    // RR case

    if (balance < -1 && data > root -> right -> data)

    {

        //printf("DEBUG\n");

        return rotateLeft(root);

    }

    // LR case

    if (balance > 1 && data > root -> left -> data)

    {

        root -> left = rotateLeft(root -> left);

        return rotateRight(root);

    }

    // RL case

    if (balance < -1 && data < root -> right -> data)

    {

        root -> right = rotateRight(root -> right);

        return rotateLeft(root);

    }

    

    // if the balance if b/w [-1, 1]

    return root;

}



//inorder traversal

void inorder(node *root)

{

    if (root)

    {

        inorder(root -> left);

        printf("%d ", root -> data);

        inorder(root -> right); 

    }

}



// Driver function

int main()

{

    node *root = NULL;

    int nodeCount = 0;



    root = insert(root, 10);

    printf("%d node is inserted\n", ++nodeCount);

    root = insert(root, 20);

    printf("%d node is inserted\n", ++nodeCount);

    root = insert(root, 30);

    printf("%d node is inserted\n", ++nodeCount);

    root = insert(root, 40);

    printf("%d node is inserted\n", ++nodeCount);

    root = insert(root, 50);

    printf("%d node is inserted\n", ++nodeCount);

    root = insert(root, 25);

    printf("%d node is inserted\n", ++nodeCount); 

    inorder(root);

    

    return 0;

}