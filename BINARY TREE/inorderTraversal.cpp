#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;

        TreeNode *curr = root;

        while (curr != NULL || !st.empty())
        {
            // Go as left as possible
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            // Process the top node
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        return ans;
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;

    vector<int> ans = obj.inorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

// RECURSIVE APPROACH OF INORDER TRAVERSAL


#include <iostream>
#include <vector>
using namespace std;

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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        // Base Case
        if (root == NULL)
            return;

        // Traverse Left Subtree
        inorder(root->left, ans);

        // Visit Root
        ans.push_back(root->val);

        // Traverse Right Subtree
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;

    vector<int> ans = obj.inorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}



//  MORRIS INORDER TRAVERSAL



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
    // Function to perform Morris Inorder Traversal
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;

        // Pointer used for traversal
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            // If there is no left subtree
            if (curr->left == nullptr)
            {
                // Visit current node
                inorder.push_back(curr->val);

                // Move to right subtree
                curr = curr->right;
            }
            else
            {
                // Find inorder predecessor
                TreeNode *prev = curr->left;

                while (prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }

                // Create thread if it doesn't exist
                if (prev->right == nullptr)
                {
                    // Create temporary thread
                    prev->right = curr;

                    // Move to left subtree
                    curr = curr->left;
                }
                else
                {
                    // Remove temporary thread
                    prev->right = nullptr;

                    // Visit current node
                    inorder.push_back(curr->val);

                    // Move to right subtree
                    curr = curr->right;
                }
            }
        }

        return inorder;
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

        Inorder: 4 2 5 1 6 3 7
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.inorderTraversal(root);

    cout << "Morris Inorder Traversal: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}