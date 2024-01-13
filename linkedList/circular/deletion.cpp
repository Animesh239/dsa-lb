// delete the node with a given value

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
    // // if the element is the last node then the tail will change
    // if (elementNode == tail || newNode->data == tail->data) {
    //     tail = newNode;
    // }
}

void deleteNode(Node* &tail, int elememt){
    // if list is empty
    if(tail == NULL){
        cout << "List is empty" << endl ;
        return ;
    }

    Node* temp = tail ;

    // if the element is the tail node
    if(temp->data == elememt){
        Node* elementNode = temp ;
        while(temp->next != tail){
            temp = temp->next ;
        }
        // now temp is the node before the tail node
        temp->next = elementNode->next ;
        tail = temp ;
        elementNode->next = NULL ;
        delete elementNode ;
        return ;
    }
    // if the element is in the middle or at the end
    while(temp->next->data != elememt){
        temp = temp->next ;
        if(temp->next == tail){
            cout << "Element not found in the list" << endl ;
            return ;
        }
    }
    // temp is the node before the element node
    Node* elementNode = temp->next;
    temp->next = elementNode->next;
    elementNode->next = NULL;
    delete elementNode;

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
    tail->next = tail ;  // make the tail point to itself
    insertNode(tail, 1, 2) ;
    insertNode(tail, 2, 3) ;
    insertNode(tail, 3, 4) ;
    insertNode(tail, 4, 5) ;

    cout << "tail->data: " << tail->data << endl ;

    deleteNode(tail, 1) ;

    printList(tail) ;

    return 0 ;
}