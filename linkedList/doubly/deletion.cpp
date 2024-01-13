// deletion from a doubly linked list

#include<iostream>
using namespace std ;

class Node{

    public:
        int data ;
        Node* next ;
        Node* prev ;

        Node(int data){
            this->data = data ;
            next = NULL ;
            prev = NULL ;
        }

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

void deletionAtHead(Node* &head){
    int length = getLength(head) ;
    if(length == 0){
        cout << "List is empty" << endl ;
        return ;
    }
    Node* temp = head ;
    head = head->next ;
    head->prev = NULL ;
    temp->next = NULL ;  
    temp->prev = NULL ; 
    delete temp ;
}

void deletionAtTail(Node* &head){
    int length = getLength(head) ;
    if(length == 0){
        cout << "List is empty" << endl ;
        return ;
    }
    Node* temp = head ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->prev->next = NULL ;
    temp->prev = NULL ;
    delete temp ;
}

void deleteAtPosition(int position , Node* &head){
    int length = getLength(head) ;
    if(position > length){
        cout << "Invalid position" << endl ;
        return ;
    }
    if(position == 1){
        deletionAtHead(head) ;
        return ;
    }
    if(position == length){
        deletionAtTail(head) ;
        return ;
    }
    Node* temp = head ;
    Node* prev = NULL ;
    for(int i = 1 ; i < position ; i++){
        prev = temp ;
        temp = temp->next ;
    }
    prev->next = temp->next ;
    temp->next->prev = prev ;
    temp->next = NULL ;
    temp->prev = NULL ;
    delete temp ;
}

int main(){

    Node* head = new Node(10) ;
    insertAtHead(head, 20) ;
    insertAtHead(head, 30) ;
    insertAtHead(head, 40) ;
    insertAtHead(head, 50) ;

    deleteAtPosition(5, head) ;

    printList(head) ;

    return 0 ;
}