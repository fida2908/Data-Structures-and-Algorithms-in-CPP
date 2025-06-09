#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

Node* copyLL(Node* head){
    unordered_map<Node*, Node*> m;

    if(head == NULL){
        return head;
    }
    
    Node* newhead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newhead;
    m[head] = newhead;
    while(oldTemp != NULL){
        Node* copyNode = new Node(oldTemp->data);
        newTemp->next = copyNode;
        m[oldTemp] = copyNode;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newhead;
    while(oldTemp!=NULL){
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newhead;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set random pointers
    head->random = head->next->next;       // 1 → 3
    head->next->random = head;             // 2 → 1
    head->next->next->random = head->next; // 3 → 2

    Node* copied = copyLL(head);

    // Print to verify
    Node* temp = copied;
    while (temp != NULL) {
        cout << "Data: " << temp->data;
        if (temp->random)
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}
