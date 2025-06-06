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

Node* middle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast != NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}

int main(){
    Node* newNode = new Node(1);
    Node* head = newNode;
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    
    printLL(middle(head));

}