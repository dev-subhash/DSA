//Fresh Code (Approach 1: count = 0) ✅ Recommended



#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Solution class
class Solution
{
public:

    // Function to calculate the length of the linked list
    int findLength(Node* head)
    {
        // Initially no nodes are counted
        int count = 0;

        // Temporary pointer used for traversal
        Node* temp = head;

        // Traverse until the end of the list
        while (temp != nullptr)
        {
            count++;            // Count current node
            temp = temp->next;  // Move to next node
        }

        // Return total number of nodes
        return count;
    }
};

int main()
{
    // Creating the linked list:
    // 10 -> 20 -> 30 -> 40 -> 50

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Solution obj;

    cout << "Length of Linked List = "
         << obj.findLength(head);

    return 0;
}




//Fresh Code (Approach 2: count = 1)
//Needs an extra if (head == nullptr) check
//less preferred



#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Solution
{
public:

    int findLength(Node* head)
    {
        // If the list is empty, its length is 0
        if (head == nullptr)
            return 0;

        // We have already counted the first node
        int count = 1;

        // Start traversal from the first node
        Node* temp = head;

        // Traverse while there is a next node
        while (temp->next != nullptr)
        {
            count++;            // Count the next node
            temp = temp->next;  // Move forward
        }

        return count;
    }
};

int main()
{
    // Creating the linked list:
    // 10 -> 20 -> 30 -> 40

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Solution obj;

    cout << "Length of Linked List = "
         << obj.findLength(head);

    return 0;
}