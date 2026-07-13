#include <iostream>
#include <queue>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Class containing the solution
class Solution {
public:
    // Function to calculate the maximum width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {

        // If the tree is empty, width is 0
        if (root == nullptr)
            return 0;

        int ans = 0;

        // Queue stores:
        // 1. Pointer to the node
        // 2. Index of the node as if the tree were a complete binary tree
        // unsigned long long is used to avoid integer overflow.
        queue<pair<TreeNode*, unsigned long long>> q;

        // Root starts with index 0
        q.push({root, 0});

        // Perform Level Order Traversal (BFS)
        while (!q.empty()) {

            unsigned long long first, last;

            // Number of nodes in the current level
            unsigned long long size = q.size();

            // Minimum index at this level
            // Used to normalize indices and prevent overflow
            unsigned long long mmin = q.front().second;

            // Traverse all nodes of the current level
            for (int i = 0; i < size; i++) {

                // Normalize the index
                unsigned long long cur_indx = q.front().second - mmin;

                TreeNode* node = q.front().first;
                q.pop();

                // Store index of the first node in this level
                if (i == 0)
                    first = cur_indx;

                // Store index of the last node in this level
                if (i == size - 1)
                    last = cur_indx;

                // Push left child with its corresponding index
                if (node->left != nullptr) {
                    q.push({node->left, cur_indx * 2 + 1});
                }

                // Push right child with its corresponding index
                if (node->right != nullptr) {
                    q.push({node->right, cur_indx * 2 + 2});
                }
            }

            // Width of current level = last index - first index + 1
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};

int main() {

    /*
            1
          /   \
         3     2
        / \     \
       5   3     9

    Maximum Width = 4
    */

    // Creating the binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    // Create Solution object
    Solution obj;

    // Print the maximum width
    cout << "Maximum Width of Binary Tree: "
         << obj.widthOfBinaryTree(root) << endl;

    return 0;
}