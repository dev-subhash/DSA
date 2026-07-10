#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Solution class
class Solution {
public:

    // Function to find the Lowest Common Ancestor (LCA)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base Case:
        // If the current node is NULL,
        // or matches either p or q,
        // return the current node.
        if (root == nullptr || root == p || root == q)
            return root;

        // Search for p and q in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search for p and q in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If left subtree doesn't contain either node,
        // return the result from the right subtree.
        if (left == nullptr)
            return right;

        // If right subtree doesn't contain either node,
        // return the result from the left subtree.
        else if (right == nullptr)
            return left;

        // If both left and right are non-null,
        // then the current node is the Lowest Common Ancestor.
        else
            return root;
    }
};

int main() {

    /*
            Construct the following Binary Tree

                    3
                  /   \
                 5     1
                / \   / \
               6   2 0   8
                  / \
                 7   4

        Find LCA of nodes 5 and 1.
        Expected Answer = 3
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes whose LCA is to be found
    TreeNode* p = root->left;   // Node 5
    TreeNode* q = root->right;  // Node 1

    // Create Solution object
    Solution obj;

    // Find the Lowest Common Ancestor
    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    // Print the result
    if (ans != nullptr)
        cout << "Lowest Common Ancestor = " << ans->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}