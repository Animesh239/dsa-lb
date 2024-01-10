// insertion in linked list

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

// double pointer is used to change the head pointer
void insertionAtHead(Node** head, int data){ // here head contains the address of the head pointer, also we are passing the address of the head pointer
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode; // head is now pointing to the new node
}

void insertionAtTail(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertionAtPosition(Node** head, int data, int position){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = *head;
    for(int i = 0; i < position - 1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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

    // print the linked list
    printList(head);
    cout << endl;

    // insert 0 at the beginning of the linked list
    insertionAtHead(&head, 0);
    printList(head);
    cout << endl;

    // insert 4 at the end of the linked list
    insertionAtTail(&head, 4);
    printList(head);
    cout << endl;

    // insert 5 at the 2nd position of the linked list
    insertionAtPosition(&head, 5, 2);
    printList(head);
    cout << endl;

    return 0;
}
