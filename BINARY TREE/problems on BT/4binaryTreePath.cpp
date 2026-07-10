#include <iostream>
#include <vector>
#include <string>

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

    // Recursive function to find all root-to-leaf paths
    void solve(TreeNode *root, string path, vector<string> &ans)
    {
        // Base Case:
        // If the current node is NULL, simply return.
        if (root == nullptr)
            return;

        // Add the current node's value to the path.
        path += to_string(root->val);

        // If the current node is a leaf node,
        // store the complete path.
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }

        // Add the arrow before moving to the next node.
        path += "->";

        // Traverse the left subtree.
        solve(root->left, path, ans);

        // Traverse the right subtree.
        solve(root->right, path, ans);
    }

    // Returns all root-to-leaf paths.
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        // Start DFS with an empty path.
        solve(root, "", ans);

        return ans;
    }
};

int main()
{
    /*
            Construct the following Binary Tree

                    1
                  /   \
                 2     3
                  \
                   5

        Root-to-Leaf Paths:
        1->2->5
        1->3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    Solution obj;

    // Get all root-to-leaf paths.
    vector<string> paths = obj.binaryTreePaths(root);

    cout << "Root to Leaf Paths are:\n";

    // Print each path.
    for (string path : paths)
    {
        cout << path << endl;
    }

    // Free allocated memory.
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}




// ITERATIVE APPROACH



#include <iostream>
#include <vector>
#include <stack>
#include <string>

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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        // If tree is empty
        if (root == nullptr)
            return ans;

        // Stack stores:
        // {Current Node, Path till Current Node}
        stack<pair<TreeNode *, string>> st;

        // Push root node with its value
        st.push({root, to_string(root->val)});

        while (!st.empty())
        {
            // Get the top element
            TreeNode *curr = st.top().first;
            string path = st.top().second;
            st.pop();

            // If it is a leaf node,
            // store the complete path.
            if (curr->left == nullptr && curr->right == nullptr)
            {
                ans.push_back(path);
            }

            // Push right child first
            if (curr->right != nullptr)
            {
                st.push({curr->right,
                         path + "->" + to_string(curr->right->val)});
            }

            // Push left child
            if (curr->left != nullptr)
            {
                st.push({curr->left,
                         path + "->" + to_string(curr->left->val)});
            }
        }

        return ans;
    }
};

int main()
{
    /*
            Construct the Binary Tree

                    1
                  /   \
                 2     3
                  \
                   5

        Paths:
        1->2->5
        1->3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    Solution obj;

    vector<string> paths = obj.binaryTreePaths(root);

    cout << "Root-to-Leaf Paths:\n";

    for (string path : paths)
    {
        cout << path << endl;
    }

    // Free memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}