// RECRURSIVE APPROACH 
#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Recursive function to search an element
bool search(Node* head, int key)
{
    // Base Case 1:
    // Reached the end of the list
    if (head == nullptr)
        return false;

    // Base Case 2:
    // Element found
    if (head->data == key)
        return true;

    // Recursive call on the remaining list
    return search(head->next, key);
}

// Function to print the linked list
void printList(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    // Creating the linked list manually
    // 1 -> 3 -> 5 -> 7 -> NULL

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);

    cout << "Linked List: ";
    printList(head);

    int key = 5;

    if (search(head, key))
        cout << key << " is present in the linked list." << endl;
    else
        cout << key << " is not present in the linked list." << endl;

    return 0;
}




// ITERATIVE APPROACH


#include <iostream>
using namespace std;

// Node class representing each node of the linked list
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to search an element in the linked list
bool search(Node* head, int key)
{
    // Pointer used to traverse the list
    Node* temp = head;

    // Traverse until the end of the list
    while (temp != nullptr)
    {
        // If the current node contains the key
        if (temp->data == key)
            return true;

        // Move to the next node
        temp = temp->next;
    }

    // Key is not present
    return false;
}

// Function to print the linked list
void printList(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    // ---------------- Creating the Linked List ----------------
    // Linked List: 1 -> 3 -> 5 -> 7 -> NULL

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Element to search
    int key = 5;

    // Search the element
    if (search(head, key))
        cout << key << " is present in the linked list." << endl;
    else
        cout << key << " is not present in the linked list." << endl;

    return 0;
}