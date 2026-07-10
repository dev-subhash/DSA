#include <iostream>
#include <algorithm>
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
    // Variable to store the maximum diameter
    int maxi = 0;

    // Function to calculate the height of a binary tree
    int maxheight(TreeNode* root)
    {
        // Base Case
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int lh = maxheight(root->left);

        // Height of right subtree
        int rh = maxheight(root->right);

        // Height of current node
        return 1 + max(lh, rh);
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root)
    {
        // Base Case
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int lh = maxheight(root->left);

        // Height of right subtree
        int rh = maxheight(root->right);

        // Update the maximum diameter
        // Diameter = Left Height + Right Height
        maxi = max(maxi, lh + rh);

        // Traverse the left subtree
        diameterOfBinaryTree(root->left);

        // Traverse the right subtree
        diameterOfBinaryTree(root->right);

        // Return the maximum diameter found so far
        return maxi;
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5

        Diameter = 3
        Path: 4 -> 2 -> 1 -> 3
    */

    // Create the binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create Solution object
    Solution obj;

    // Find and print the diameter
    cout << "Diameter of Binary Tree = "
         << obj.diameterOfBinaryTree(root) << endl;

    return 0;
}