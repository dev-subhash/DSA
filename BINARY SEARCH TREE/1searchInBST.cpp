#include <iostream>
using namespace std;

// Structure of a Binary Search Tree Node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
    Function: searchBST()

    Searches for a given key in the Binary Search Tree.

    Parameters:
    root -> Pointer to the root of the BST.
    key  -> Value to search.

    Returns:
    Pointer to the node containing the key if found.
    Otherwise returns NULL.
*/
TreeNode* searchBST(TreeNode* root, int key)
{
    // Base Case:
    // If tree is empty or key is found
    if (root == NULL || root->data == key)
        return root;

    // If key is smaller than current node,
    // search in the left subtree.
    if (key < root->data)
        return searchBST(root->left, key);

    // Otherwise search in the right subtree.
    return searchBST(root->right, key);
}

int main()
{
    /*
            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80
    */

    // Manually creating the BST
    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(30);
    root->right = new TreeNode(70);

    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);

    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    // Element to search
    int key = 60;

    // Call the search function
    TreeNode* result = searchBST(root, key);

    // Display the result
    if (result != NULL)
    {
        cout << "Element " << key << " found in the BST." << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the BST." << endl;
    }

    return 0;
}


/*
Time Complexity
Best Case: O(1) (key found at the root)
Average Case (Balanced BST): O(log n)
Worst Case (Skewed BST): O(n)
*/

/*
Space Complexity
Recursive Solution: O(h) where h is the height of the tree.
Balanced BST: O(log n)
Skewed BST: O(n)

*/