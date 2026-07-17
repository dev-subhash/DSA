/*
What is Lowest Common Ancestor?

The Lowest Common Ancestor (LCA) of two nodes P and Q is the lowest (deepest) node in the BST that has both P and Q as descendants.

A node can also be its own ancestor.

Algorithm

Start from root.

Repeat:

If both values are smaller

→ Move left.

Else if both values are larger

→ Move right.

Otherwise

→ Current node is LCA.

Time Complexity
Average Case : O(log N)

Worst Case : O(N)

Worst case happens when BST is skewed.

Space Complexity
Iterative : O(1)

Recursive : O(H)

H = Height of tree

*/




#include <iostream>
using namespace std;

// Structure of a BST node
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
    // If tree is empty
    if (root == NULL)
    {
        return new Node(key);
    }

    // Insert in left subtree
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }

    // Insert in right subtree
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    // Return root
    return root;
}

// Function to find Lowest Common Ancestor
Node* LCA(Node* root, int p, int q)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    // Both nodes are smaller
    if (p < root->data && q < root->data)
    {
        return LCA(root->left, p, q);
    }

    // Both nodes are greater
    if (p > root->data && q > root->data)
    {
        return LCA(root->right, p, q);
    }

    // One node is on left and other is on right
    // OR current node is equal to one of them
    return root;
}

int main()
{
    Node* root = NULL;

    // Creating BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    insert(root, 2);
    insert(root, 7);

    int p = 2;
    int q = 15;

    Node* ans = LCA(root, p, q);

    if (ans != NULL)
    {
        cout << "Lowest Common Ancestor of "
             << p << " and " << q
             << " is : " << ans->data << endl;
    }
    else
    {
        cout << "LCA not found." << endl;
    }

    return 0;
}

