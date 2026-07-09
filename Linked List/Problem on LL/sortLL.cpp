//  BRUTE FORCE APPROACH

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* sortList(ListNode* head) {

        // Empty list or single node is already sorted.
        if (head == nullptr || head->next == nullptr)
            return head;

        // Vector to store all node values.
        vector<int> nums;

        // Traverse the linked list and store values.
        ListNode* temp = head;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the vector.
        sort(nums.begin(), nums.end());

        // Traverse the linked list again
        // and replace node values with sorted values.
        temp = head;
        int i = 0;

        while (temp != nullptr) {
            temp->val = nums[i];
            i++;
            temp = temp->next;
        }

        // Return the head of the sorted linked list.
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
    // 4 -> 2 -> 1 -> 3 -> 5

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    head = obj.sortList(head);

    cout << "Sorted Linked List:\n";
    printList(head);

    return 0;
}

// MERGE SORT ON LINKED LIST ( OPTIMAL APPROACH)

#include <iostream>
using namespace std;

// Definition of the ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    // Function to find the middle node of the linked list.
    // For an even-length list, it returns the first middle node.
    ListNode* findmiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Function to merge two sorted linked lists.
    ListNode* merge(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify merging.
        ListNode* dummynode = new ListNode(-1);

        // Tail pointer of the merged list.
        ListNode* temp = dummynode;

        // Compare nodes from both lists and attach the smaller one.
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        // Attach the remaining nodes.
        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;

        // Return the head of the merged list.
        return dummynode->next;
    }

    // Merge Sort function.
    ListNode* sortList(ListNode* head) {

        // Base case:
        // If the list has 0 or 1 node, it is already sorted.
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find the middle node.
        ListNode* middle = findmiddle(head);

        // Divide the list into two halves.
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;

        // Break the linked list.
        middle->next = nullptr;

        // Recursively sort both halves.
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        // Merge the sorted halves.
        return merge(lefthead, righthead);
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
    // 4 -> 2 -> 1 -> 3 -> 5

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    head = obj.sortList(head);

    cout << "Sorted Linked List:\n";
    printList(head);

    return 0;
}