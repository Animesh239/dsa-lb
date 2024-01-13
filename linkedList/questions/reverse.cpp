// reverse of a linkedList

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

// void reverse(Node* head){
//     if(head == NULL || head->next == NULL){
//         return ;
//     }
//     Node* curr = head ;
//     Node* prev = NULL ;
//     Node* forward = NULL ;

//     while(curr!=NULL){
//         forward = curr->next ;
//         curr->next = prev ;
//         prev = curr ;
//         curr = forward ;
//     }
//     head = prev ;
//     printList(head) ;
// }

Node* reverseByRecursion(Node* curr, Node* prev) {
    if (curr == nullptr) {
        return prev;
    }

    Node* forward = curr->next;
    curr->next = prev;
    return reverseByRecursion(forward, curr);
}

void solve(Node* &head) {
    Node* curr = head;
    Node* prev = nullptr;
    head = reverseByRecursion(curr, prev);
}

int main(){
    Node* head = new Node(1) ;
    Node* second = new Node(2) ;
    Node* third = new Node(3) ;
    Node* fourth = new Node(4) ;
    Node* fifth = new Node(5) ;

    head->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;

    printList(head) ;
    solve(head) ;
    printList(head) ;

    return 0 ;
}