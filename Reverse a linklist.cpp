#include <iostream>

using namespace std;

// Definition of the ListNode structure
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev and current one step forward
        current = next;
    }

    return prev;  // prev will be the new head of the reversed list
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reversing the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Clean up the memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
