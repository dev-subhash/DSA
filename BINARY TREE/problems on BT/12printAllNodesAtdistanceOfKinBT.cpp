#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Structure of a Binary Tree Node
struct TreeNode
{
    int val;            // Value stored in the node
    TreeNode *left;     // Pointer to left child
    TreeNode *right;    // Pointer to right child

    // Constructor
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

    // Function to store the parent of every node
    // This helps us move upward in the tree.
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();

            // Store parent of left child
            if (current->left)
            {
                parent[current->left] = current;
                q.push(current->left);
            }

            // Store parent of right child
            if (current->right)
            {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Function to return all nodes at distance K from target
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        // Stores parent of every node
        unordered_map<TreeNode*, TreeNode*> parent;

        // Build parent mapping
        markParents(root, parent);

        // Keeps track of visited nodes
        unordered_map<TreeNode*, bool> visited;

        // BFS queue
        queue<TreeNode*> q;

        // Start BFS from target node
        q.push(target);
        visited[target] = true;

        int currentLevel = 0;

        while (!q.empty())
        {
            int size = q.size();

            // If we've reached distance K, stop
            if (currentLevel == k)
                break;

            currentLevel++;

            // Traverse one complete level
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                // Visit left child
                if (node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Visit right child
                if (node->right && !visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Visit parent
                if (parent[node] && !visited[parent[node]])
                {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        // Nodes remaining in queue are exactly K distance away
        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main()
{
    /*
                3
              /   \
             5     1
            / \   / \
           6   2 0   8
              / \
             7   4
    */

    // Create all nodes
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Target node is 5
    TreeNode* target = root->left;

    // Required distance
    int K = 2;

    Solution obj;

    vector<int> ans = obj.distanceK(root, target, K);

    cout << "Nodes at distance " << K
         << " from target node " << target->val << " are:\n";

    for (int node : ans)
        cout << node << " ";

    cout << endl;

    return 0;
}