#include<iostream>
using namespace std;

class Node{
    public:
        int data ;
        Node* next;
};

void printList(Node* n){
    while( n != NULL){
        cout << n->data << " " ;
        n = n->next ;
    }
}

void insertionAtHead(int data , Node** head){
    Node* newNode = new Node();
    newNode->data  = data ;
    newNode->next = *head ;
    *head = newNode ;
}

void insertionAtTail(int data , Node** tail){
    Node* newNode = new Node();
    newNode->data = data ;
    newNode->next = NULL ;
     
    (*tail)->next = newNode ;

    *tail = newNode ;
}

void insertionAtPosition(int data , int position , Node** head){
    Node* newNode = new Node();
    newNode->data = data ;
    newNode->next = NULL ;

    Node* temp = *head ;
    for(int i = 1 ; i < position ; i++){
        temp = temp->next ;
    }
    newNode->next = temp->next ;
    temp->next = newNode ;
}

int main(){
    Node* head = NULL ;
    Node* second = NULL ;
    Node* third = NULL ;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1 ;
    head->next = second ;

    second->data = 2 ;
    second->next = third ;

    third->data = 3 ;
    third->next = NULL ;

    printList(head);
    cout << endl ;

    insertionAtHead(0 , &head);
    printList(head);
    cout << endl ;

    insertionAtTail(4 , &third);
    printList(head);
    cout << endl ;

    insertionAtPosition(5 , 3 , &head);
    printList(head);
    cout << endl ;

    return 0;
}