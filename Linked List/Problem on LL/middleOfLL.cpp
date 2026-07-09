#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to find the middle node
ListNode* middleNode(ListNode* head) {

    // Variable to count the total number of nodes
    int cnt = 0;

    // Temporary pointer for traversal
    ListNode* temp = head;

    // Count the total nodes in the linked list
    while (temp) {
        cnt++;
        temp = temp->next;
    }

    // Calculate the position of the middle node
    // For even length, this gives the second middle node.
    int pos = cnt / 2 + 1;

    // Start again from the head
    temp = head;

    // Move to the middle position
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    // Return the middle node
    return temp;
}

int main() {

    // Creating the linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Find the middle node
    ListNode* middle = middleNode(head);

    // Print the value of the middle node
    cout << "Middle Node: " << middle->val << endl;

    return 0;
}



//OPTIMAL APPROACH  --HARE AND TORTOISE METHOD


#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to find the middle node using
// Hare and Tortoise (Fast and Slow Pointer) method
ListNode* middleNode(ListNode* head) {

    // Both pointers start from the head
    ListNode* slow = head;
    ListNode* fast = head;
    /* if we use fast=head->next ,
     it will give first middle.
     */
    /* PTR- if we use fast=head->next->next,
    then we get the node befor the middle node.
    */

    // Move slow by one step and fast by two steps
    while (fast != nullptr && fast->next != nullptr) {

        // Slow pointer moves one node
        slow = slow->next;

        // Fast pointer moves two nodes
        fast = fast->next->next;
    }

    // When the loop ends, slow points to the middle node
    return slow;
}

int main() {

    // Creating the linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Find the middle node
    ListNode* middle = middleNode(head);

    // Print the value of the middle node
    cout << "Middle Node: " << middle->val << endl;

    return 0;
}

