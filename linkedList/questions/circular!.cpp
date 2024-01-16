// check if a linked list is circular or not

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node* n){
    Node* temp = n ;
    do{
        cout << temp->data << " " ;
        temp = temp->next ;
    }while(temp != n) ;
    cout << endl ;
}

bool isCircular(Node* head){
    if(head == nullptr){
        return true ;
    }

    Node* temp = head->next ;
    while(temp != nullptr && temp != head){
        temp = temp->next ;
    }

    return (temp == head) ;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = head ;

    printList(head) ;
    isCircular(head) ? cout << "Yes" << endl : cout << "No" << endl ;

    return 0;
}