#include <iostream>
#include <algorithm> // For max()
#include <cmath>     // For abs()

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

// Solution class
class Solution
{
public:

    // Function to check whether the tree is balanced
    bool isBalanced(TreeNode* root)
    {
        return checkBalanced(root);
    }

private:

    // Function to calculate the maximum height of a tree
    int maxHeight(TreeNode* root)
    {
        // Base Case
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int leftHeight = maxHeight(root->left);

        // Height of right subtree
        int rightHeight = maxHeight(root->right);

        // Height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to check whether every node is balanced
    bool checkBalanced(TreeNode* root)
    {
        // Empty tree is balanced
        if (root == nullptr)
            return true;

        // Calculate left and right subtree heights
        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);

        // If height difference is greater than 1,
        // tree is not balanced
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        // Check recursively for left and right subtrees
        return checkBalanced(root->left) &&
               checkBalanced(root->right);
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

        This tree is balanced.
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is Not Balanced" << endl;

    return 0;
}