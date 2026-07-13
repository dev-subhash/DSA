/*Mathematically,

Node Value=Left Child Value+Right Child Value
*/


#include <iostream>
using namespace std;

// Structure for a Binary Tree Node
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

class Solution {
public:

    // Function to check whether the binary tree satisfies
    // the Children Sum Property
    bool checkChildrenSum(TreeNode* root) {

        // An empty tree satisfies the property
        if (root == nullptr)
            return true;

        // A leaf node also satisfies the property
        if (root->left == nullptr && root->right == nullptr)
            return true;

        // Store left and right child values
        int leftValue = 0;
        int rightValue = 0;

        if (root->left)
            leftValue = root->left->val;

        if (root->right)
            rightValue = root->right->val;

        // Check current node and recursively check left and right subtrees
        return (root->val == leftValue + rightValue) &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};

int main() {

    /*
            Constructing the following tree

                  10
                 /  \
                8    2
               / \    \
              3   5    2

        Every node satisfies:
        Parent = Left Child + Right Child
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(8);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(2);

    Solution obj;

    if (obj.checkChildrenSum(root))
        cout << "Children Sum Property is Satisfied." << endl;
    else
        cout << "Children Sum Property is NOT Satisfied." << endl;

    return 0;
}