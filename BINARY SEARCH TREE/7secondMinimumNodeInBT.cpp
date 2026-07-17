#include <iostream>
#include <vector>

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

    // Function to perform Inorder Traversal
    // Left -> Root -> Right
    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        // Base case
        if (root == nullptr)
            return;

        // Visit left subtree
        inorderTraversal(root->left, ans);

        // Store current node value
        ans.push_back(root->val);

        // Visit right subtree
        inorderTraversal(root->right, ans);
    }

    // Function to find the second minimum value in the tree
    int findSecondMinimumValue(TreeNode *root)
    {
        vector<int> ans;

        // Store all node values using inorder traversal
        inorderTraversal(root, ans);

        // Initialize smallest and second smallest
        long long smallest = 3000000000LL;
        long long secondSmallest = 3000000000LL;

        // Traverse all values
        for (int i = 0; i < ans.size(); i++)
        {
            // Found a new smallest value
            if (ans[i] < smallest)
            {
                secondSmallest = smallest;
                smallest = ans[i];
            }

            // Update second smallest
            else if (ans[i] < secondSmallest && ans[i] != smallest)
            {
                secondSmallest = ans[i];
            }
        }

        // If second smallest doesn't exist
        if (secondSmallest == 3000000000LL)
            return -1;

        return secondSmallest;
    }
};

int main()
{
    /*
            2
           / \
          2   5
             / \
            5   7

        Smallest = 2
        Second Smallest = 5
    */

    // Creating the tree
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(2);

    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution obj;

    // Find second minimum value
    int answer = obj.findSecondMinimumValue(root);

    cout << "Second Minimum Value = " << answer << endl;

    return 0;
}