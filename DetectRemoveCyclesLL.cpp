#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* DetectRemove(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;
    Node* prev = NULL;

    // Detect cycle using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    if (!isCycle) {
        return head;  // No cycle
    }

    // Find the start of the cycle
    slow = head;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the cycle
    prev->next = NULL;

    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a cycle: 1->2->3->4->2...
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Creates a cycle at node 2

    // Detect and remove the cycle
    head = DetectRemove(head);

    // Print the corrected list
    cout << "List after removing cycle: ";
    printLL(head);

    return 0;
}
