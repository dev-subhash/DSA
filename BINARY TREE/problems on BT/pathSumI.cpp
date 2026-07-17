// RECURSIVE APPROACH
#include <iostream>
using namespace std;

// Definition of a Tree Node
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // Base Case:
        // If the tree is empty, no path exists.
        if (root == nullptr)
            return false;

        // If the current node is a leaf node
        // (i.e., it has no left or right child)
        if (root->left == nullptr && root->right == nullptr)
        {
            // Check whether the remaining target
            // is equal to the current node's value.
            return (targetSum == root->val);
        }

        // Recursively check the left and right subtree.
        // Subtract the current node's value from targetSum.
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main()
{
    /*
            Construct the following tree

                    5
                  /   \
                 4     8
                /     / \
              11    13   4
             /  \
            7    2

        Target Sum = 22

        Valid Path:
        5 -> 4 -> 11 -> 2
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    int targetSum = 22;

    Solution obj;

    if (obj.hasPathSum(root, targetSum))
        cout << "Path with sum " << targetSum << " exists." << endl;
    else
        cout << "Path with sum " << targetSum << " does not exist." << endl;

    return 0;
}



//   ITERATIVE APPROACH(USING STACK)



#include <iostream>
#include <stack>
#include <utility>
using namespace std;

// Definition of a Tree Node
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // If the tree is empty, no path exists.
        if (root == nullptr)
            return false;

        // Stack stores:
        // 1. Pointer to the current node
        // 2. Remaining sum after including the current node
        stack<pair<TreeNode *, int>> st;

        // Push the root node with the remaining sum
        st.push({root, targetSum - root->val});

        // Traverse until the stack becomes empty
        while (!st.empty())
        {
            // Get the top element
            TreeNode *curr = st.top().first;
            int remainingSum = st.top().second;

            // Remove it from the stack
            st.pop();

            // If the current node is a leaf node
            if (curr->left == nullptr && curr->right == nullptr)
            {
                // If the remaining sum becomes 0,
                // a valid root-to-leaf path exists.
                if (remainingSum == 0)
                    return true;
            }

            // Push the right child first
            // (Left will be processed first because stack is LIFO)
            if (curr->right != nullptr)
            {
                st.push({curr->right,
                         remainingSum - curr->right->val});
            }

            // Push the left child
            if (curr->left != nullptr)
            {
                st.push({curr->left,
                         remainingSum - curr->left->val});
            }
        }

        // No valid path found
        return false;
    }
};

int main()
{
    /*
            Construct the following tree

                    5
                  /   \
                 4     8
                /     / \
              11    13   4
             /  \
            7    2

        Target Sum = 22

        Valid Path:
        5 -> 4 -> 11 -> 2
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    int targetSum = 22;

    Solution obj;

    if (obj.hasPathSum(root, targetSum))
        cout << "Path with sum " << targetSum << " exists." << endl;
    else
        cout << "Path with sum " << targetSum << " does not exist." << endl;

    return 0;
}