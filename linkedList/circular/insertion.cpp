// circular linked list intro

#include<iostream>
using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;

        Node(int data){
            this->data = data ;
            next = NULL ;
        }

        ~Node(){
            int value = this->data ;
            if( this->next != NULL){
                delete next ;
                this->next = NULL ;
            }
            cout << "Deleting node with value: " << value << endl ;
        }
};

void insertNode(Node* &tail, int element, int data){

    // if list is empty
    if(tail == NULL){
        Node* newNode = new Node(data) ;
        newNode->next = newNode ;
        tail = newNode ;
        return ;
    }
    
    Node* elementNode = tail ;
    while(elementNode->data != element){
        elementNode = elementNode->next ;
        if(elementNode == tail){
            cout << "Element not found in the list" << endl ;
            return ;
        }
    }
    // elementNode is the node after which we have to insert the new node and now the element node is on the element
    Node* newNode = new Node(data) ;
    newNode->next = elementNode->next ;
    elementNode->next = newNode ;
    // if the element is the last node then the tail will change
    // if (elementNode == tail || newNode->data == tail->data) {
    //     tail = newNode;
    // }
}

void printList(Node* tail){
    Node* temp = tail ;
    do{
        cout << temp->data << " " ;
        temp = temp->next ;
    }while(temp != tail) ;
    cout << endl ;
}

int main(){
    Node* tail = new Node(1) ;
    tail->next = tail ;
    // insertNode(tail, 1, 2) ;
    insertNode(tail, 1, 2) ;
    insertNode(tail, 2, 3) ;
    insertNode(tail, 3, 4) ;

    printList(tail) ;
}