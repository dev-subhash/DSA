#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // Function to invert (mirror) the binary tree
    TreeNode* invertTree(TreeNode* root)
    {
        // Base Case:
        // If the current node is NULL, simply return.
        if (root == nullptr)
            return nullptr;

        // Store the left child in a temporary pointer
        TreeNode* temp = root->left;

        // Swap the left and right child
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left subtree
        invertTree(root->left);

        // Recursively invert the right subtree
        invertTree(root->right);

        // Return the root of the inverted tree
        return root;
    }
};

// Function for Inorder Traversal
void inorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    /*
            Original Tree

                4
              /   \
             2     7
            / \   / \
           1   3 6   9
    */

    // Creating the binary tree
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Print inorder traversal before inversion
    cout << "Inorder Traversal Before Inverting: ";
    inorder(root);
    cout << endl;

    Solution obj;

    // Invert the binary tree
    obj.invertTree(root);

    // Print inorder traversal after inversion
    cout << "Inorder Traversal After Inverting : ";
    inorder(root);
    cout << endl;

    return 0;
}   