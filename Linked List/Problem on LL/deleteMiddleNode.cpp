#include <iostream>
using namespace std;

// Definition of a singly linked list node.
struct ListNode {
    int val;
    ListNode* next;

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with value and next pointer
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    // Function to find the node just before the middle node.
    // We initialize fast = head->next->next so that
    // slow stops at the previous node of the middle.
    ListNode* middleNode(ListNode* head) {

        // Slow pointer moves one step.
        ListNode* slow = head;

        // Fast pointer moves two steps.
        ListNode* fast = head->next->next;

        // Traverse until fast reaches the end.
        while (fast != nullptr && fast->next != nullptr) {

            // Move slow by one node.
            slow = slow->next;

            // Move fast by two nodes.
            fast = fast->next->next;
        }

        // slow now points to the node before the middle.
        return slow;
    }

    // Function to delete the middle node.
    ListNode* deleteMiddle(ListNode* head) {

        // If the list is empty or contains only one node,
        // deleting the middle results in an empty list.
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // Find the node just before the middle node.
        ListNode* prevMiddle = middleNode(head);

        // Store the middle node.
        ListNode* temp = prevMiddle->next;

        // Skip the middle node.
        prevMiddle->next = prevMiddle->next->next;

        // Delete the middle node.
        delete temp;

        // Return the updated head.
        return head;
    }
};

// Function to print the linked list.
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // Creating the linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    // Delete the middle node.
    head = obj.deleteMiddle(head);

    cout << "Linked List after deleting the middle node:\n";
    printList(head);

    return 0;
}