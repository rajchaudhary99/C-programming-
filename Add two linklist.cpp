#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to add a new node at the end of the linked list
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to add two linked lists
Node* addTwoLists(Node* l1, Node* l2) {
    Node* result = nullptr;
    Node* prev = nullptr;
    Node* temp = nullptr;
    int carry = 0, sum;

    while (l1 != nullptr || l2 != nullptr || carry) {
        // Calculate the sum of the current digits and carry
        sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        // Update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        
        // Update sum to single digit
        sum = sum % 10;
        
        // Create a new node with the sum and add it to the result list
        temp = new Node(sum);
        if (result == nullptr) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }
    
    return result;
}

int main() {
    // Create first linked list: 2 -> 4 -> 3 (represents number 342)
    Node* l1 = nullptr;
    append(l1, 2);
    append(l1, 4);
    append(l1, 3);

    // Create second linked list: 5 -> 6 -> 4 (represents number 465)
    Node* l2 = nullptr;
    append(l2, 5);
    append(l2, 6);
    append(l2, 4);

    std::cout << "First List: ";
    printList(l1);

    std::cout << "Second List: ";
    printList(l2);

    Node* result = addTwoLists(l1, l2);

    std::cout << "Sum List: ";
    printList(result);

    return 0;
}
