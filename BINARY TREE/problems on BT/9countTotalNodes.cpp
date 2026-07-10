#include <iostream>
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

// Solution class
class Solution {
public:

    // Function to calculate the height of the rightmost path
    int findrightheight(TreeNode* root) {
        int height = 0;

        // Traverse only through the right children
        while (root != nullptr) {
            height++;
            root = root->right;
        }

        return height;
    }

    // Function to calculate the height of the leftmost path
    int findleftheight(TreeNode* root) {
        int height = 0;

        // Traverse only through the left children
        while (root != nullptr) {
            height++;
            root = root->left;
        }

        return height;
    }

    // Function to count the total number of nodes
    int countNodes(TreeNode* root) {

        // Base case: Empty tree has 0 nodes
        if (root == nullptr)
            return 0;

        // Calculate leftmost and rightmost heights
        int lh = findleftheight(root);
        int rh = findrightheight(root);

        // If both heights are equal,
        // the tree is a perfect binary tree.
        // Number of nodes = 2^height - 1
        if (lh == rh)
            return (1 << lh) - 1;

        // Otherwise recursively count nodes
        // in the left and right subtrees.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {

    /*
            Construct the following Complete Binary Tree

                    1
                  /   \
                 2     3
                / \   /
               4   5 6

            Total Nodes = 6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    // Create Solution object
    Solution obj;

    // Count the total number of nodes
    cout << "Total Number of Nodes = " << obj.countNodes(root) << endl;

    return 0;
}