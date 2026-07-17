/*
Problem Statement

Given the root of a binary tree, return the boundary traversal of the tree in anti-clockwise direction.

The boundary of a binary tree consists of three parts:

Left Boundary (excluding leaf nodes)
All Leaf Nodes (from left to right)
Right Boundary (excluding leaf nodes, added in reverse order)

The root is included only once.

*/


#include <iostream>
#include <vector>

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
    //----------------------------------------------------
    // Check whether a node is a leaf node
    //----------------------------------------------------
    bool isLeaf(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    //----------------------------------------------------
    // Add Left Boundary (excluding leaf nodes)
    //----------------------------------------------------
    void addLeftBoundary(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->left;

        while (curr)
        {
            // Ignore leaf nodes
            if (!isLeaf(curr))
                ans.push_back(curr->val);

            // Prefer left child
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    //----------------------------------------------------
    // Add all Leaf Nodes
    //----------------------------------------------------
    void addLeaves(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        // If current node is a leaf, add it
        if (isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    //----------------------------------------------------
    // Add Right Boundary (excluding leaf nodes)
    //----------------------------------------------------
    void addRightBoundary(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->right;

        vector<int> temp;

        while (curr)
        {
            // Ignore leaf nodes
            if (!isLeaf(curr))
                temp.push_back(curr->val);

            // Prefer right child
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Add in reverse order
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    //----------------------------------------------------
    // Boundary Traversal Function
    //----------------------------------------------------
    vector<int> boundaryTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        // Add root if it is not a leaf
        if (!isLeaf(root))
            ans.push_back(root->val);

        // Step 1: Left Boundary
        addLeftBoundary(root, ans);

        // Step 2: Leaf Nodes
        addLeaves(root, ans);

        // Step 3: Right Boundary
        addRightBoundary(root, ans);

        return ans;
    }
};

int main()
{
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
              / \
             8   9
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    Solution obj;

    vector<int> ans = obj.boundaryTraversal(root);

    cout << "Boundary Traversal: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}