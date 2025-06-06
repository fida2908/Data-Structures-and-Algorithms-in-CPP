#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }    
};

Node* ReverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL){
        next =  curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        
    }
    return prev;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}


    int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printLL(head);

    
    head = ReverseLL(head);

    cout << "Reversed List: ";
    printLL(head);

    return 0;
}