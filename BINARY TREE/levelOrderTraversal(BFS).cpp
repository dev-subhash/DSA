#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Stores the final answer
        vector<vector<int>> ans;

        // If the tree is empty, return an empty vector
        if (root == NULL)
            return ans;

        // Queue is used for BFS traversal
        queue<TreeNode *> q;

        // Push the root node into the queue
        q.push(root);

        // Continue until all nodes are processed
        while (!q.empty())
        {
            // Number of nodes present at the current level
            int size = q.size();

            // Stores all node values of the current level
            vector<int> level;

            // Process every node of the current level
            for (int i = 0; i < size; i++)
            {
                // Get the front node of the queue
                TreeNode *node = q.front();

                // Remove it from the queue
                q.pop();

                // Store the current node's value
                level.push_back(node->val);

                // If the left child exists, push it into the queue
                if (node->left != NULL)
                    q.push(node->left);

                // If the right child exists, push it into the queue
                if (node->right != NULL)
                    q.push(node->right);
            }

            // Store the current level in the final answer
            ans.push_back(level);
        }

        return ans;
    }
};

int main()
{
    /*
            Binary Tree

                 1
               /   \
              2     3
             / \     \
            4   5     6
    */

    // Creating the tree
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;

    // Perform Level Order Traversal
    vector<vector<int>> ans = obj.levelOrder(root);

    // Print the traversal level by level
    cout << "Level Order Traversal:\n";

    for (auto level : ans)
    {
        for (int value : level)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}