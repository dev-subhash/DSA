// USING MORRIS PREORDER TRAVERSAL  SC=O(1) AND TC=O(N);


#include <iostream>
using namespace std;

// Definition of Binary Tree Node
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
    // Function to flatten the binary tree into a linked list
    void flatten(TreeNode *root)
    {
        // Start from the root node
        TreeNode *curr = root;

        // Traverse until all nodes are processed
        while (curr != nullptr)
        {
            // If the current node has a left subtree
            if (curr->left != nullptr)
            {
                // Find the rightmost node of the left subtree
                TreeNode *prev = curr->left;

                while (prev->right != nullptr)
                {
                    prev = prev->right;
                }

                // Connect the original right subtree
                // to the rightmost node of the left subtree
                prev->right = curr->right;

                // Move the left subtree to the right
                curr->right = curr->left;

                // Set left child to NULL
                curr->left = nullptr;
            }

            // Move to the next node
            curr = curr->right;
        }
    }
};

// Function to print the flattened linked list
void printLinkedList(TreeNode *root)
{
    while (root != nullptr)
    {
        cout << root->val << " ";

        // Left child should always be NULL
        if (root->left != nullptr)
        {
            cout << "Error: Left child is not NULL!" << endl;
            return;
        }

        root = root->right;
    }
    cout << endl;
}

int main()
{
    /*
            Constructing the following tree

                    1
                   / \
                  2   5
                 / \   \
                3   4   6

        Flattened Linked List:
        1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;

    // Flatten the tree
    obj.flatten(root);

    cout << "Flattened Linked List:" << endl;
    printLinkedList(root);

    return 0;
}



//   RECURSIVE SOLUTION 


#include <iostream>
using namespace std;

// Definition of Binary Tree Node
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
    // Stores the previously visited node
    TreeNode *prev = nullptr;

    // Function to flatten the binary tree
    void flatten(TreeNode *root)
    {
        // Base case
        if (root == nullptr)
            return;

        // Step 1: Flatten the right subtree
        flatten(root->right);

        // Step 2: Flatten the left subtree
        flatten(root->left);

        // Step 3: Connect current node to previously processed node
        root->right = prev;

        // Step 4: Left child should always be NULL
        root->left = nullptr;

        // Step 5: Update previous node
        prev = root;
    }
};

// Function to print the flattened linked list
void printList(TreeNode *root)
{
    while (root != nullptr)
    {
        cout << root->val << " ";

        // Move to next node
        root = root->right;
    }

    cout << endl;
}

int main()
{
    /*
            Constructing the following tree

                    1
                   / \
                  2   5
                 / \   \
                3   4   6

        Flattened Linked List:
        1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;

    // Flatten the tree
    obj.flatten(root);

    cout << "Flattened Linked List:" << endl;
    printList(root);

    return 0;
}