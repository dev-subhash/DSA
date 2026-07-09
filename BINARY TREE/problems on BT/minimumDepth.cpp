#include <iostream>
#include <algorithm>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

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
    // Function to find the minimum depth of a binary tree
    int minDepth(TreeNode *root)
    {
        // Base Case:
        // If the tree is empty, its depth is 0.
        if (root == nullptr)
            return 0;

        // If there is no left child,
        // we must continue through the right subtree.
        if (root->left == nullptr)
            return minDepth(root->right) + 1;

        // If there is no right child,
        // we must continue through the left subtree.
        if (root->right == nullptr)
            return minDepth(root->left) + 1;

        // If both left and right children exist,
        // choose the subtree with the smaller depth.
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main()
{
    /*
            Construct the following Binary Tree

                    1
                  /   \
                 2     3
                /
               4
              /
             5

        Minimum Depth = 2
        Path: 1 -> 3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    Solution obj;

    cout << "Minimum Depth of the Binary Tree = "
         << obj.minDepth(root) << endl;

    // Free the allocated memory
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}