#include<iostream>
using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;
};

void printList(Node* n){
    while( n!= NULL){
        cout << n->data << " " ;
        n = n->next ;
    }
};

void deleteAtHead(Node** head){
    Node* temp = *head ;  // store the address of head in temp
    *head = temp->next ;  // change the head to the next node
    delete temp ;
}

void deleteAtTail(Node** tail){
    Node* temp = *tail ; // store the address of tail in temp
    Node* prev = NULL ; // store the address of the previous node 

    // traverse the list till the second last node
    while(temp->next != NULL){
        prev = temp ;
        temp = temp->next ;
    }

    prev->next = NULL ; // make the second last node point to NULL
    *tail = prev ; // change the tail to the second last node
    delete temp ;
}

void deleteAtPosition(int position , Node** head){

    if(position == 1){
        deleteAtHead(head) ;
        return ;
    }

    

    Node* temp = *head ;
    Node* prev = NULL ;

    // traverse the list till the node to be deleted
    for(int i = 1 ; i < position ; i++){
        prev = temp ;
        temp = temp->next ;
    }
    // make the previous node point to the next node of the node to be deleted
    prev->next = temp->next ;
    delete temp ;
}

int main(){
    Node* head = NULL ;
    Node* second = NULL ;
    Node* third = NULL ;
    Node* fourth = NULL ;
    Node* fifth = NULL ;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    head->data = 1 ;
    head->next = second ;

    second->data = 2 ;
    second->next = third ;

    third->data = 3 ;
    third->next = fourth ;

    fourth->data = 4 ;
    fourth->next = fifth ;

    fifth->data = 5 ;
    fifth->next = NULL ;

    printList(head) ;
    cout << endl ;

    deleteAtHead(&head) ;
    printList(head) ;
    cout << endl ;

    deleteAtTail(&fifth) ;
    printList(head) ;
    cout << endl ;

    deleteAtPosition(2 , &head) ;
    printList(head) ;
    cout << endl ;

    return 0 ;
}
