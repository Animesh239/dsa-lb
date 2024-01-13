#include<iostream>
using namespace std ;

class Node{

    public:
        int data ;
        Node* next ;
        Node* prev ;

    // constructor
    Node(int data){
        this->data = data ;
        next = NULL ;
        prev = NULL ;
    }

    // destructor
    ~Node(){
        int value = this->data ;
        if( this->next != NULL){
            this->next = NULL ;
            delete next ;
        }
        if( this->prev != NULL){
            this->prev = NULL ;
            delete prev ;
        }
        cout << "Deleting node with value: " << value << endl ;
    }
};

void printList(Node* n){
    while( n!= NULL){
        cout << n->data << " " ;
        n = n->next ;
    }
    cout << endl ;
};

int getLength(Node* head){
    int length = 0 ;
    while(head != NULL){
        length++ ;
        head = head->next ;
    }
    return length ;
}

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data) ;
   // newNode->prev = NULL ; // already done in constructor
    newNode->next = head ;
    head->prev = newNode ;
    head = newNode ;
}

void insertionAtTail(Node* &tail, int data){
    Node* newNode = new Node(data) ;
    // newNode->next = NULL ; // already done in constructor
    newNode->prev = tail ;
    tail->next = newNode ;
    tail = newNode ;
}

void insertionAtTailFromHead(Node* &head , int data){
    Node* newNode = new Node(data) ;
    Node* temp = head ;
    // traverse the list till the last node
    while(temp->next != NULL){
        temp = temp->next ;
    }
    // now temp is the tail node
    newNode->prev = temp ;
    temp->next = newNode ;
    temp = newNode ;
}

void insertAtPosition(Node* &head, int position , int data){
    Node* newNode = new Node(data) ;
    Node* temp = head ;
    Node* prevNode = head ; // previous node of the node to be inserted

    // traverse the list till the node to be inserted
    for(int i = 1 ; i < position ; i++){
        prevNode = temp ;
        temp = temp->next ;
    }
    // now temp is at the position where the node is to be inserted and prevNode is the previous node
    newNode->prev = prevNode ;
    newNode->next = temp ;
    prevNode->next = newNode ;
    temp->prev = newNode ;
}

int main(){
    Node* head = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;

    head->next = second ;
    second->next = third ;
    second->prev = head ;
    third->prev = second ;

    insertAtHead(head, 5) ;
    insertionAtTail(third, 40) ;
    insertionAtTailFromHead(head, 50) ;

    cout << "Length of the list: " << getLength(head) << endl ;

    printList(head) ;
}