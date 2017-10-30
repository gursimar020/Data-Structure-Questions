#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>





typedef struct node

{

    struct node *left, *right;

    int data;

    // red ==> true, black ==> false

    bool color; 

} node;







// utility function to create a node.

node* createNode(int data, bool color)

{

    node *myNode = (node *) malloc(sizeof(node));

    myNode -> left = myNode -> right = NULL;

    myNode -> data = data;



    // New Node which is created is

    // always red in color.

    myNode -> data = true;

    return myNode;

}



// utility funciton to rotate node anticlockwise.

node* rotateLeft(node* myNode)

{

    printf("left rotation!!\n");

    node *child = myNode -> right;

    node *childLeft = child -> left;





    child -> left = myNode;

    myNode -> right = childLeft;



    return child;

}



// utility function to rotate node clockwise.

node* rotateRight(node* myNode)

{

    printf("right rotation\n");

    node *child = myNode -> left;

    node *childRight =  child -> right;



    child -> right = myNode;

    myNode -> left = childRight;

    



    return child; 

}



// utility funciton to check whether

// node is red in color or not.

int isRed(node *myNode)

{

    if (myNode == NULL) return 0;



    return (myNode -> color == true);

}



// utility function to swap color of two 

// nodes.

void swapColors(node *node1, node *node2)

{

    bool temp = node1 -> color;

    node1 -> color = node2 -> color;

    node2 -> color = temp;

}



// insertion into Left Leaning Red Black Tree.

node* insert(node* myNode, int data)

{

    // Normal insertion code for any Binary Search tree. 

    if (myNode == NULL) 

        return createNode(data, color);

    



    if (data < myNode -> data) 

        myNode -> left = insert(myNode -> left, data);



    else if (data > myNode -> data) 

        myNode -> right = insert(myNode -> right, data);



    else    

        return myNode;



    

    // case 1.

    // when right child is Red but left child is

    // Black or doesn't exist.

    if (isRed(myNode -> right) && !isRed(myNode -> left))

    {

        // left rotate the node to make it into

        // valid structure.

        myNode = rotateLeft(myNode);



        // swap the colors as the child node 

        // should always be red

        swapColors(myNode, myNode -> left);

        

    }

    

    // case 2

    // when left child as well as left grand child in Red

    if (isRed(myNode -> left) && isRed(myNode -> left -> left))

    {   

        // right rotate the current node to make 

        // it into a valid structure.

        myNode = rotateRight(myNode);

        swapColors(myNode, myNode -> left);

    }

    

    

    // case 3

    // when both left and right child are Red in color.

    if (isRed(myNode -> left) && isRed(myNode -> right))

    {

        // invert the color of node as well 

        // it's left and right child.

        myNode -> color = !myNode -> color;

        myNode -> left -> color = myNode -> right -> color = false; // change the color to black.

    }



    return myNode;

}



//inorder traversal

void inorder(node *node)

{

    if (node)

    {

        inorder(node -> left);

        printf("%d ", node -> data);

        inorder(node -> right); 

    }

}



// Driver function

int main()

{

    node *root = NULL;

    int nodeCount = 0;

    /* 

        LLRB tree made after all insertions are made.

            

    1. Nodes which have double INCOMING edge means

       that they are RED in color.

    2. Nodes which have single INCOMING edge means

       that they are BLACK in color.

    

        root

         |

         40

       //  \

      20    50

     /  \

   10    30

        //

       25 

    

    */



    root = insert(root, 10);

    // to make sure that root remains

    // black is color

    root -> color = false;

    printf("%d node is inserted\n", ++nodeCount);

    

    root = insert(root, 20);

    root -> color = false;

    printf("%d node is inserted\n", ++nodeCount);

    

    root = insert(root, 30);

    root -> color = false;

    printf("%d node is inserted\n", ++nodeCount);

   

    root = insert(root, 40);

    root -> color = false;

    printf("%d node is inserted\n", ++nodeCount);

    

    root = insert(root, 50);

    root -> color = false; 

    printf("%d node is inserted\n", ++nodeCount);

    

    root = insert(root, 25);

    root -> color = false;

    printf("%d node is inserted\n", ++nodeCount); 

    

    inorder(root);

    

    return 0;

}