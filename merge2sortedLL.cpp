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


Node* merge(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return head1 == NULL ? head2 : head1;
    }

    if(head1->data <= head2->data){
        head1->next = merge(head1->next, head2);
        return head1;
    }else{
        head2->next = merge(head1, head2->next);
        return head2;
    }

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
   
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
  

    Node* head1 = new Node(2);
    head1->next = new Node(3);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(7);
   
     printLL(head);
     printLL(head1);

    head = merge(head,head1);

    // Print the corrected list
    cout << "List: ";
    printLL(head);

    return 0;
}
