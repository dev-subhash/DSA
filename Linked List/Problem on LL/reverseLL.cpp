// ITERATIVE APPROACH

#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to reverse linked list iteratively
Node* reverseList(Node* head)
{
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr)
    {
        // Store next node
        Node* nextNode = curr->next;

        // Reverse current node's pointer
        curr->next = prev;

        // Move prev and curr forward
        prev = curr;
        curr = nextNode;
    }

    // prev becomes the new head
    return prev;
}

// Function to print linked list
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

int main()
{
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original List:\n";
    printList(head);

    head = reverseList(head);

    cout << "\n\nReversed List:\n";
    printList(head);

    return 0;
}



// RECURSIVE APPROACH


#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Recursive function to reverse linked list
Node* reverseList(Node* head)
{
    // Base Case:
    // Empty list or single node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Reverse remaining list
    Node* newHead = reverseList(head->next);

    // Reverse current link
    head->next->next = head;

    // Make current node the last node
    head->next = nullptr;

    return newHead;
}

// Function to print linked list
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

int main()
{
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original List:\n";
    printList(head);

    head = reverseList(head);

    cout << "\n\nReversed List:\n";
    printList(head);

    return 0;
}