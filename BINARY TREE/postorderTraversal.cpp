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
    void postorder(TreeNode *root, vector<int> &ans)
    {
        // Base Case
        if (root == NULL)
            return;

        // Traverse Left Subtree
        postorder(root->left, ans);

        // Traverse Right Subtree
        postorder(root->right, ans);

        // Visit Root
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
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

    vector<int> ans = obj.postorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}


// ITERATIVE APPROACH  (USING TWO STACKS)


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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode *> st1, st2;

        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();

            st2.push(node);

            if (node->left)
                st1.push(node->left);

            if (node->right)
                st1.push(node->right);
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
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

    vector<int> ans = obj.postorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}


// ITERATIVE APPROACH (USING ONE STACK)

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;

        TreeNode *curr = root;
        TreeNode *lastVisited = NULL;

        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *node = st.top();

                if (node->right != NULL && lastVisited != node->right)
                {
                    curr = node->right;
                }
                else
                {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
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

    vector<int> ans = obj.postorderTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

