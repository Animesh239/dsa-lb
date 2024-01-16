// reverse in k nodal group

#include<iostream>
using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;

    Node(int data){
        this->data = data ;
        this->next = nullptr ;
    }
};

void printList(Node* n){
    while(n != nullptr){
        cout << n->data << " " ;
        n = n->next ;
    }
    cout << endl ;
}

Node* reverseK(Node* head, int k){
    if(head == nullptr || head->next == nullptr){
        return head ;
    }
    
    int count = 0 ;
    Node* curr = head ;
    Node* prev = nullptr ;
    Node* forward = nullptr ;

    while(count < k && curr != nullptr){
        forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
        count++ ;
    }

    if(forward != nullptr){
        head->next = reverseK(forward, k) ;
    }

    return prev ;
}

int main(){

    Node* head = new Node(1) ;
    Node* second = new Node(2) ;
    Node* third = new Node(3) ;
    Node* fourth = new Node(4) ;
    Node* fifth = new Node(5) ;
    Node* sixth = new Node(6) ;

    head->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;
    fifth->next = sixth ;

    printList(head) ;
    // printList(reverseK(head, 3)) ;
    // printList(reverseK(head, 2)) ;
    printList(reverseK(head, 4)) ;

    return 0 ;
}