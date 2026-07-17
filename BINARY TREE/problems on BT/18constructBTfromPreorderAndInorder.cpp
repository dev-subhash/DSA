#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
private:
    // Stores the index of every value in inorder traversal
    unordered_map<int, int> inorderMap;

    // Recursive function to build tree
    TreeNode* buildTreeHelper(vector<int>& preorder,
                              int preStart,
                              int preEnd,
                              vector<int>& inorder,
                              int inStart,
                              int inEnd)
    {
        // Base case
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element in preorder is the root
        int rootValue = preorder[preStart];

        // Create root node
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int rootIndex = inorderMap[rootValue];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = buildTreeHelper(preorder,
                                     preStart + 1,
                                     preStart + leftSize,
                                     inorder,
                                     inStart,
                                     rootIndex - 1);

        // Build right subtree
        root->right = buildTreeHelper(preorder,
                                      preStart + leftSize + 1,
                                      preEnd,
                                      inorder,
                                      rootIndex + 1,
                                      inEnd);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // Store inorder indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder,
                               0,
                               preorder.size() - 1,
                               inorder,
                               0,
                               inorder.size() - 1);
    }
};

// Inorder Traversal
void inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(TreeNode* root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Preorder Traversal of Constructed Tree:\n";
    preorderTraversal(root);

    cout << "\n\n";

    cout << "Inorder Traversal of Constructed Tree:\n";
    inorderTraversal(root);

    cout << endl;

    return 0;
}