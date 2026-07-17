#include <iostream>
using namespace std;

// Structure for a BST node
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//------------------------------------------------------
// Function to insert a node into the BST
//------------------------------------------------------
Node* insert(Node* root, int value)
{
    // If tree is empty, create a new node
    if (root == NULL)
        return new Node(value);

    // Insert in left subtree
    if (value < root->data)
        root->left = insert(root->left, value);

    // Insert in right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

//------------------------------------------------------
// Function to find the minimum node in BST
//------------------------------------------------------
Node* findMin(Node* root)
{
    // If tree is empty
    if (root == NULL)
        return NULL;

    // Keep moving to the left child
    while (root->left != NULL)
    {
        root = root->left;
    }

    // Leftmost node is the minimum
    return root;
}

//------------------------------------------------------
// Function to find the maximum node in BST
//------------------------------------------------------
Node* findMax(Node* root)
{
    // If tree is empty
    if (root == NULL)
        return NULL;

    // Keep moving to the right child
    while (root->right != NULL)
    {
        root = root->right;
    }

    // Rightmost node is the maximum
    return root;
}

//------------------------------------------------------
// Main Function
//------------------------------------------------------
int main()
{
    Node* root = NULL;

    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);

    // Find minimum node
    Node* minNode = findMin(root);

    // Find maximum node
    Node* maxNode = findMax(root);

    // Display results
    if (minNode != NULL)
        cout << "Minimum value in BST = " << minNode->data << endl;

    if (maxNode != NULL)
        cout << "Maximum value in BST = " << maxNode->data << endl;

    return 0;
}