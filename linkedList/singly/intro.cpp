#include<iostream>
using namespace std; 

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    // assign data in first node and link it with second node
    head->data = 1;
    head->next = second;

    // assign data in second node and link it with third node
    second->data = 2;
    second->next = third;

    // assign data in third node and link it with NULL
    third->data = 3;
    third->next = NULL;

    printList(head);

    return 0;
}
