#include <iostream>
#include <vector>
using namespace std;

// Definition of a BST Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    // Function to perform Inorder Traversal
    // Inorder traversal of BST always gives nodes in sorted order
    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        // Base Case
        if (root == NULL)
            return;

        // Visit left subtree
        inorderTraversal(root->left, ans);

        // Store current node value
        ans.push_back(root->val);

        // Visit right subtree
        inorderTraversal(root->right, ans);
    }

    // Function to find Kth Smallest Element
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;

        // Store inorder traversal
        inorderTraversal(root, ans);

        // kth smallest element is at index (k-1)
        return ans[k - 1];
    }
};

// Function to insert a node into BST
TreeNode* insert(TreeNode* root, int value)
{
    // If tree is empty, create new node
    if (root == NULL)
        return new TreeNode(value);

    // Insert in left subtree
    if (value < root->val)
        root->left = insert(root->left, value);

    // Insert in right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to print inorder traversal
void inorder(TreeNode* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode* root = NULL;

    // Creating BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);

    cout << "Inorder Traversal of BST: ";
    inorder(root);

    cout << endl;

    Solution obj;

    int k = 3;

    cout << "The " << k << "rd smallest element is: "
         << obj.kthSmallest(root, k);

    return 0;
}




//OPTIMIZED APPROACH


#include <iostream>
using namespace std;

// Definition of a Binary Search Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    // Function to perform Inorder Traversal
    // Inorder traversal of a BST visits nodes in sorted order.
    void inorderTraversal(TreeNode *root, int k, int &cnt, int &ans)
    {
        // Base case: if tree is empty
        if (root == NULL)
            return;

        // Visit left subtree
        inorderTraversal(root->left, k, cnt, ans);

        // Count the current node
        cnt++;

        // If this is the kth node, store its value
        if (cnt == k)
            ans = root->val;

        // Visit right subtree
        inorderTraversal(root->right, k, cnt, ans);
    }

    // Function to find kth smallest element
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0;   // Counts visited nodes
        int ans = 0;   // Stores kth smallest element

        inorderTraversal(root, k, cnt, ans);

        return ans;
    }
};

// Function to insert a node into BST
TreeNode* insert(TreeNode* root, int value)
{
    // If tree is empty, create a new node
    if (root == NULL)
        return new TreeNode(value);

    // Insert into left subtree
    if (value < root->val)
        root->left = insert(root->left, value);

    // Insert into right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to print inorder traversal
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = NULL;

    // Creating the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    Solution obj;

    int k = 3;

    // Find kth smallest element
    int result = obj.kthSmallest(root, k);

    cout << "The " << k << "rd smallest element is: " << result << endl;

    return 0;
}