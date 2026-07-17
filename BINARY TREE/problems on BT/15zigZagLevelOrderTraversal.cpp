/*
Binary Tree Zigzag Level Order Traversal
Problem Statement

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.

Traverse the first level from left to right.
Traverse the second level from right to left.
Continue alternating the direction for every level.
*/


#include <iostream>
#include <vector>
#include <queue>
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
    /*
        Function:
        Performs Zigzag Level Order Traversal of a Binary Tree.

        Idea:
        1. Use normal Level Order Traversal (BFS).
        2. Store one level at a time.
        3. Reverse every alternate level.
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        // Empty tree
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        // true  -> Left to Right
        // false -> Right to Left
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();

            // Stores one complete level
            vector<int> level;

            // Traverse all nodes of current level
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Store current node value
                level.push_back(node->val);

                // Push children for next level
                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }

            // Reverse current level if required
            if (!leftToRight)
            {
                reverse(level.begin(), level.end());
            }

            // Store level in answer
            ans.push_back(level);

            // Change traversal direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};

int main()
{
    /*
            Constructing the following tree

                    1
                  /   \
                 2     3
                / \   / \
               4   5 6   7

        Expected Output:

        1
        3 2
        4 5 6 7
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";

    for (auto &level : ans)
    {
        for (int value : level)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}