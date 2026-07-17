/*
ALGORITHM



Delete(root, key)

1. Search for the node.

2. If key < root
       delete in left subtree

3. Else if key > root
       delete in right subtree

4. Else (node found)

      Case 1:
      No child
      return NULL

      Case 2:
      One child
      return that child

      Case 3:
      Two children
      Find inorder successor
      Copy successor value
      Delete successor

*/



#include <iostream>
using namespace std;

// Definition of a BST Node
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

// Function to insert a node into BST
Node* insert(Node* root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to find the minimum value node
// (Leftmost node in the subtree)
Node* findMin(Node* root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int key)
{
    // Tree is empty
    if (root == NULL)
        return NULL;

    // Search in left subtree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // Search in right subtree
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else
        {
            // Find inorder successor
            Node* temp = findMin(root->right);

            // Replace current node's value
            root->data = temp->data;

            // Delete successor node
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder Traversal (Sorted Order)
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    // Creating BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder before deletion:\n";
    inorder(root);

    cout << "\n\nDeleting node 50...\n";

    root = deleteNode(root, 50);

    cout << "\nInorder after deletion:\n";
    inorder(root);

    return 0;
}