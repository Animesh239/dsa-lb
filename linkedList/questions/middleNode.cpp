// find middle node of linked list

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

Node* middleNode(Node* head){
    if (head == NULL) {
        return NULL; // Handle the case of an empty linked list
    }
    Node* slow = head ;
    Node* fast = head ;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow ;
}

//another iterartive approach
Node* middleNode2(Node* head){
    Node* curr = head ;
    int count = getLength(head) ;
    curr = head ;
    for(int i=0 ; i<count/2 ; i++){
        curr = curr->next ;
    }
    return curr ;
}

int main(){

    Node* head = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* fourth = new Node(40) ;
    Node* fifth = new Node(50) ;

    head->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;
    fifth->next = NULL ;

    printList(head) ;

    cout<< "middle node is: " << middleNode(head)->data << " or " << middleNode2(head)->data << endl ;

    return 0 ;
}