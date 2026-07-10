#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

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
    // Function to find the sum of all left leaves
    int sumOfLeftLeaves(TreeNode* root)
    {
        // Base Case: If tree is empty, return 0
        if (root == nullptr)
            return 0;

        // Variable to store the sum
        int sum = 0;

        // Check whether the left child exists and is a leaf node
        // A leaf node has no left or right child
        if (root->left != nullptr &&
            root->left->left == nullptr &&
            root->left->right == nullptr)
        {
            // Add the left leaf value to the sum
            sum += root->left->val;
        }

        // Recursively calculate sum in left subtree
        sum += sumOfLeftLeaves(root->left);

        // Recursively calculate sum in right subtree
        sum += sumOfLeftLeaves(root->right);

        // Return the total sum
        return sum;
    }
};

int main()
{
    /*
                3
              /   \
             9     20
                  /  \
                 15   7

        Left Leaves:
        9 and 15

        Sum = 9 + 15 = 24
    */

    // Creating the tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create Solution object
    Solution obj;

    // Print the answer
    cout << "Sum of Left Leaves = "
         << obj.sumOfLeftLeaves(root) << endl;

    return 0;
}