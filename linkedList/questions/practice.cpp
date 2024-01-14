// reverse in a iterative and recursive way of a SLL

#include<iostream>
using namespace std;

class Node{
    public:
        int data; 
        Node* next ;

        // condtructor
        Node(int data){
            this->data = data ;
            next = NULL ;
        }
} ;

void printList(Node* n){
    while( n != nullptr ){
        cout << n->data << " " ;
        n = n->next ;
    }
    cout << endl ;
}

void reverseByItr(Node* &head){
    Node* curr = head ;
    Node* prev = nullptr ;
    Node* forward = nullptr ;

    if( head->next == nullptr || head == NULL ){
        printList(head) ;
    }

    while(curr != nullptr){
        forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
    }
    return printList(prev) ;
}

Node* reverseByRecursion(Node* curr, Node* prev){
     if (curr == nullptr) {
        return prev;
    }
    Node* forward = curr->next ;
    curr->next = prev ;
    reverseByRecursion(forward , curr ) ;
}

void solve(Node* &head){
    Node* curr = head ;
    Node* prev = nullptr ;
    head = reverseByRecursion(curr, prev) ;
}

Node* reverse(Node* head){
    // base case
    if(head == NULL || head->next == nullptr){
        return head ;
    }
    Node* subHead =reverse(head->next) ;
    head->next->next = head ;
    head->next = nullptr ;
    return subHead ;
}

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* tail = new Node(4);

    head->next = second ;
    second->next = third ;
    third->next = tail ;

    printList(head) ;
    // reverseByItr(head) ;
    // solve(head) ;
    // printList(head);
    printList(reverse(head))
 ;
    return 0 ;
}
