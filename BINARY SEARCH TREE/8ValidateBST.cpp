#include <iostream>
#include <vector>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

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

    // Function to perform Inorder Traversal
    // Left -> Root -> Right
    void inorderTraversal(TreeNode* root, vector<int>& ans)
    {
        // Base case: if tree is empty
        if (root == NULL)
            return;

        // Visit left subtree
        inorderTraversal(root->left, ans);

        // Store current node value
        ans.push_back(root->val);

        // Visit right subtree
        inorderTraversal(root->right, ans);
    }

    // Function to check whether the tree is a BST
    bool isValidBST(TreeNode* root)
    {
        vector<int> ans;

        // Store inorder traversal in the vector
        inorderTraversal(root, ans);

        // Check if inorder traversal is strictly increasing
        for (int i = 1; i < ans.size(); i++)
        {
            // If current element is smaller than or equal to previous,
            // then the tree is NOT a BST.
            if (ans[i] <= ans[i - 1])
                return false;
        }

        // Tree satisfies BST property
        return true;
    }
};

int main()
{
    /*
              8
            /   \
           3     10
          / \      \
         1   6      14
            / \     /
           4   7   13

        Inorder Traversal:
        1 3 4 6 7 8 10 13 14

        Since inorder is sorted,
        this is a BST.
    */

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Tree is a Valid BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}



//   BETTER APPROACH








#include <iostream>
#include <climits>   // For LLONG_MIN and LLONG_MAX
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default Constructor
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value and child pointers
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};

class Solution
{
public:

    // Recursive function to check whether the tree is a valid BST.
    //
    // Parameters:
    // root   -> Current node
    // minval -> Minimum value the current node is allowed to have
    // maxval -> Maximum value the current node is allowed to have
    //
    // Returns:
    // true  -> If the subtree is a valid BST
    // false -> Otherwise
    bool solve(TreeNode *root, long long minval, long long maxval)
    {
        // An empty tree is always a valid BST.
        if (root == nullptr)
            return true;

        // If current node violates the allowed range,
        // then the BST property is violated.
        if (root->val <= minval || root->val >= maxval)
            return false;

        // Check the left subtree.
        // Every node in the left subtree must be smaller
        // than the current node.
        bool leftBST = solve(root->left, minval, root->val);

        // Check the right subtree.
        // Every node in the right subtree must be greater
        // than the current node.
        bool rightBST = solve(root->right, root->val, maxval);

        // The tree is a BST only if both subtrees are BSTs.
        return leftBST && rightBST;
    }

    // Function to check whether the given binary tree is a BST.
    bool isValidBST(TreeNode *root)
    {
        // Initially, the root can take any value from
        // LLONG_MIN to LLONG_MAX.
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main()
{
    /*
            5
          /   \
         3     7
        / \   / \
       2   4 6   8

       This is a valid BST.
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "The given tree is a Valid BST." << endl;
    else
        cout << "The given tree is NOT a Valid BST." << endl;

    return 0;
}

