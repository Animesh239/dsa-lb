// remove duplicates in a sorted/unsorted linked list   

#include <iostream>
#include<map>
using namespace std;

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

void removeDuplicates(Node* head){
    if(head == nullptr){
        return ;
    }

    map<int, bool> duplicate ;
    Node* temp = head ;
    Node* prev = nullptr ;

    while(temp != nullptr){
        if(duplicate[temp->data]){
            prev->next = temp->next ;
        }
        else{
            duplicate[temp->data] = true ;
            prev = temp ;
        }

        temp = temp->next ;
    }
}

void removeDuplicatesSorted(Node* head){
    if(head == nullptr){
        return ;
    }

    Node* temp = head ;
    Node* prev = nullptr ;

    while(temp != nullptr){
        if(prev != nullptr && prev->data == temp->data){
            prev->next = temp->next ;
        }else{
            prev = temp ;
        }
        temp = temp->next ;
    }
}

int main(){

    Node* head = new Node(1) ;
    Node* second = new Node(2) ;
    Node* third = new Node(2) ;
    Node* fourth = new Node(2) ;
    Node* fifth = new Node(3) ;
    Node* sixth = new Node(6) ;

    head->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;
    fifth->next = sixth ;

    printList(head) ;
    removeDuplicates(head) ;
    printList(head) ;

    return 0;
}