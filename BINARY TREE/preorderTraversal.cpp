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
    void preorder(TreeNode *root, vector<int> &ans)
    {
        // Base Case
        if (root == NULL)
            return;

        // Visit Root
        ans.push_back(root->val);

        // Traverse Left Subtree
        preorder(root->left, ans);

        // Traverse Right Subtree
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(root, ans);
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

    vector<int> ans = obj.preorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

// ITERATIVE APPROACH OF PREORDER TRAVERSAL

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode *> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            ans.push_back(node->val);

            if (node->right)
                st.push(node->right);

            if (node->left)
                st.push(node->left);
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

    vector<int> ans = obj.preorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}