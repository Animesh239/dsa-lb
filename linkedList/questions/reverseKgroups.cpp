#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// Node* reverseByRecursion(Node* curr, Node* prev) {
//     // base case
//     if (curr == nullptr) {
//         return prev;
//     }
//     Node* forward = curr->next;
//     curr->next = prev;
//     return reverseByRecursion(forward, curr);
// }

Node* kReverse(Node* head, int k) {
    // base case
    if(head == nullptr || head->next == NULL){
        return head ;
    }
    // reverse first k nodes
    Node* prev = NULL ;
    Node* forward = NULL ;
    Node* curr = head ;

    int count = 0;
    while(count < k){
        forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
        count++ ;
    }
    // head is now the last node of the reversed list, if forward is nullptr then we have reached the end of the list
    if(forward != nullptr){
        head->next = kReverse(forward , k) ;
    } 

    // prev is the new head of the reversed list
    return prev ;
}

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;


    printList(head);
    // printList(reverseByRecursion(head, nullptr));
    printList(kReverse(head, 3));


    return 0 ;
}