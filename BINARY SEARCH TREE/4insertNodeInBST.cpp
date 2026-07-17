/*
Problem Statement

Given the root of a Binary Search Tree (BST) and a value key, insert the value into the BST while maintaining the BST property.

The BST property is:

All nodes in the left subtree are smaller than the current node.
All nodes in the right subtree are greater than the current node.

If the tree is empty, the new node becomes the root.
*/



#include <iostream>
using namespace std;

// Definition of a BST node
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
    // If tree is empty, create a new node
    if (root == NULL)
        return new Node(key);

    // If key is smaller, insert into left subtree
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    // If key is greater, insert into right subtree
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    // If key already exists, do nothing
    // (BST generally does not store duplicate values)

    return root;
}

// Inorder Traversal (Left -> Root -> Right)
// Prints elements in sorted order for BST
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

    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST before inserting 65:" << endl;
    inorder(root);
    cout << endl;

    // Insert a new node
    insert(root, 65);

    cout << "\nBST after inserting 65:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}



//  ITERATIVE APPROACH



#include <iostream>
using namespace std;

// Definition of a BST node
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node into the BST iteratively
Node* insert(Node* root, int key)
{
    // If the tree is empty, create the root node
    if (root == NULL)
        return new Node(key);

    // 'curr' is used to traverse the BST
    Node* curr = root;

    // Traverse the tree until the correct position is found
    while (curr != NULL)
    {
        // If the key is smaller, move to the left subtree
        if (key < curr->data)
        {
            // If left child is empty, insert the new node here
            if (curr->left == NULL)
            {
                curr->left = new Node(key);
                break; // Insertion completed
            }

            // Otherwise, continue moving left
            curr = curr->left;
        }

        // If the key is greater, move to the right subtree
        else if (key > curr->data)
        {
            // If right child is empty, insert the new node here
            if (curr->right == NULL)
            {
                curr->right = new Node(key);
                break; // Insertion completed
            }

            // Otherwise, continue moving right
            curr = curr->right;
        }

        // If the key already exists, do not insert duplicates
        else
        {
            break;
        }
    }

    // Return the root of the BST
    return root;
}

// Inorder Traversal (prints BST in sorted order)
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

    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST before inserting 65:" << endl;
    inorder(root);
    cout << endl;

    // Insert a new node
    insert(root, 65);

    cout << "\nBST after inserting 65:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}