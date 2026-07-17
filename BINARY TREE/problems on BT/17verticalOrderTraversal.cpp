#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    /*
        Stores each node as a tuple:
        (column, row, value)

        Column:
            Left Child  -> col - 1
            Right Child -> col + 1

        Row:
            Depth of the node
    */
    vector<tuple<int, int, int>> nodes;

    /*
        DFS Traversal

        Parameters:
        root -> Current node
        row  -> Current depth
        col  -> Current vertical column
    */
    void dfs(TreeNode* root, int row, int col) {

        // Base Case
        if (root == nullptr)
            return;

        // Store current node information
        nodes.push_back(make_tuple(col, row, root->val));

        // Traverse left subtree
        dfs(root->left, row + 1, col - 1);

        // Traverse right subtree
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Perform DFS and store coordinates of every node
        dfs(root, 0, 0);

        /*
            Sort tuples in lexicographical order.

            Sorting priority:
            1. Column
            2. Row
            3. Node Value

            tuple automatically follows this order.
        */
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        // Keeps track of the previous column
        int prevCol = INT_MIN;

        // Traverse the sorted tuples
        for (size_t i = 0; i < nodes.size(); i++) {

            // Extract column, row and node value
            int col = get<0>(nodes[i]);
            int row = get<1>(nodes[i]);   // Row is extracted for completeness
            int val = get<2>(nodes[i]);

            // If a new column starts, create a new vector
            if (col != prevCol) {
                ans.push_back(vector<int>());
                prevCol = col;
            }

            // Add node value to the current column
            ans.back().push_back(val);
        }

        return ans;
    }
};

int main() {

    /*
            Construct the following tree

                    3
                   / \
                  9   20
                     /  \
                    15   7

            Expected Output

            9
            3 15
            20
            7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create object of Solution class
    Solution obj;

    // Get Vertical Order Traversal
    vector<vector<int>> ans = obj.verticalTraversal(root);

    // Print the answer
    cout << "Vertical Order Traversal:\n";

    for (size_t i = 0; i < ans.size(); i++) {

        for (size_t j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}