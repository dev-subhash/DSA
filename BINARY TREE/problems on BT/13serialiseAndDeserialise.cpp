#include <iostream>
#include <queue>
#include <sstream>
#include <string>

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

class Codec
{
public:

    //=========================================================
    // Function to Serialize Binary Tree
    // Converts Tree -> String
    //=========================================================
    string serialize(TreeNode *root)
    {
        // If tree is empty
        if (root == nullptr)
            return "";

        string ans = "";

        // Queue for Level Order Traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // Get front node
            TreeNode *curr = q.front();
            q.pop();

            // If node is NULL
            if (curr == nullptr)
            {
                ans += "N ";
                continue;
            }

            // Store current node value
            ans += to_string(curr->val) + " ";

            // Push left and right child
            // (Even if they are NULL)
            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    //=========================================================
    // Function to Deserialize
    // Converts String -> Binary Tree
    //=========================================================
    TreeNode *deserialize(string data)
    {
        // Empty string means empty tree
        if (data.empty())
            return nullptr;

        // Used to read values one by one
        stringstream ss(data);

        string value;

        // Read first value (Root)
        ss >> value;

        TreeNode *root = new TreeNode(stoi(value));

        // Queue for Level Order Construction
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // Current parent node
            TreeNode *parent = q.front();
            q.pop();

            //---------------- Left Child ----------------//

            // Read next value
            ss >> value;

            // If not NULL
            if (value != "N")
            {
                TreeNode *leftChild = new TreeNode(stoi(value));

                parent->left = leftChild;

                q.push(leftChild);
            }

            //---------------- Right Child ----------------//

            // Read next value
            ss >> value;

            // If not NULL
            {
                if (value != "N")
                {
                    TreeNode *rightChild = new TreeNode(stoi(value));

                    parent->right = rightChild;

                    q.push(rightChild);
                }
            }
        }

        return root;
    }
};

//=========================================================
// Level Order Traversal
// Used to verify reconstructed tree
//=========================================================
void levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    cout << endl;
}

//=========================================================
// Main Function
//=========================================================
int main()
{
    /*
                1
              /   \
             2     3
                  / \
                 4   5

    */

    // Create Binary Tree
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);

    root->right->right = new TreeNode(5);

    Codec obj;

    //---------------- Serialize ----------------//

    string serializedTree = obj.serialize(root);

    cout << "Serialized Tree:\n";
    cout << serializedTree << endl;

    //---------------- Deserialize ----------------//

    TreeNode *newRoot = obj.deserialize(serializedTree);

    cout << "\nLevel Order Traversal After Deserialization:\n";
    levelOrder(newRoot);

    return 0;
}