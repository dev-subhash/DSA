/*
Problem Statement

Given the root of a binary tree, find the maximum path sum.

A path is defined as a sequence of nodes where each pair of adjacent nodes is connected by an edge.

A path can start and end at any node in the tree.
Each node can appear only once in the path.
The path does not need to pass through the root.

Return the maximum path sum.
*/
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// Definition of Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

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
    // Stores the maximum path sum found so far
    int maxSum = INT_MIN;

    /*
        Returns the maximum gain that can be extended to the parent.

        At every node:
        1. Compute left gain.
        2. Compute right gain.
        3. Ignore negative gains.
        4. Update the maximum path passing through this node.
        5. Return the best single path to parent.
    */
    int solve(TreeNode *root)
    {
        // Base case
        if (root == nullptr)
            return 0;

        // Maximum gain from left subtree
        // Ignore if negative
        int leftGain = max(0, solve(root->left));

        // Maximum gain from right subtree
        int rightGain = max(0, solve(root->right));

        // Maximum path passing through current node
        int currentPath = leftGain + root->val + rightGain;

        // Update overall answer
        maxSum = max(maxSum, currentPath);

        // Return only one side to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return maxSum;
    }
};

int main()
{
    /*
              -10
             /   \
            9     20
                 /  \
                15   7

        Maximum Path:
        15 -> 20 -> 7

        Sum = 42
    */

    TreeNode *root = new TreeNode(-10);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);

    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(root)
         << endl;

    return 0;
}