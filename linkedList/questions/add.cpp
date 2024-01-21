// add two linked list

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void printList(Node* n){
    while(n != nullptr){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// approach: reverse both the linked lists and add them and then reverse the resultant linked list
Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* forward = nullptr;

    while(curr != nullptr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* solve(Node* first, Node* second){
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while(first != nullptr || second != nullptr || carry != 0){  
        int sum = 0 ;
        if(first != nullptr){
            sum += first->data;
            first = first->next;
        }
        if(second != nullptr){
            sum += second->data;
            second = second->next;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;

        Node* newNode = new Node(sum);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }        
      }
    return head;
}

Node* addTwoLists(Node* first, Node* second){
    if(first == nullptr){
        return second;
    }
    if(second == nullptr){
        return first;
    }

    first = reverse(first);
    second = reverse(second);

    return reverse(solve(first, second));
}

int main(){

    Node* head1 = new Node(1);
    Node* first1 = new Node(2);
    Node* second1 = new Node(3);
    Node* third1 = new Node(4);
    Node* fourth1 = new Node(5);
    Node* fifth1 = new Node(6);
    Node* sixth1 = new Node(7);
    Node* seventh1 = new Node(8);
    Node* eighth1 = new Node(9);

    head1->next = first1;
    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = sixth1;
    sixth1->next = seventh1;
    seventh1->next = eighth1;

    Node* head2 = new Node(9);
    Node* first2 = new Node(8);
    Node* second2 = new Node(7);
    Node* third2 = new Node(6);
    Node* fourth2 = new Node(5);
    Node* fifth2 = new Node(4);
    Node* sixth2 = new Node(3);
    Node* seventh2 = new Node(2);
    Node* eighth2 = new Node(1);

    head2->next = first2;
    first2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = sixth2;
    sixth2->next = seventh2;
    seventh2->next = eighth2;

    printList(head1);
    printList(head2);

    Node* head = addTwoLists(head1, head2);
    printList(head);

    return 0;
}