
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

    // Function to remove the nth node from the end of the linked list.
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // If the list is empty or contains only one node,
        // deleting the nth node from the end results in an empty list.
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // goalnode will eventually point to the node
        // just before the node that needs to be deleted.
        ListNode* goalnode = head;

        // lastnode is used as the fast pointer.
        ListNode* lastnode = head;

        // Move the fast pointer 'n' steps ahead.
        int cnt = 1;
        while (cnt <= n) {
            lastnode = lastnode->next;
            cnt++;
        }

        // If fast pointer becomes nullptr,
        // it means the head node must be deleted.
        if (lastnode == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both pointers together until
        // lastnode reaches the last node.
        while (lastnode->next != nullptr) {
            goalnode = goalnode->next;
            lastnode = lastnode->next;
        }

        // Store the node to be deleted.
        ListNode* temp = goalnode->next;

        // Remove the node from the linked list.
        goalnode->next = goalnode->next->next;

        // Free the memory of the deleted node.
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

    // Remove the 2nd node from the end.
    int n = 2;
    head = obj.removeNthFromEnd(head, n);

    cout << "Linked List after removing the " << n
         << "th node from the end:\n";
    printList(head);

    return 0;
}