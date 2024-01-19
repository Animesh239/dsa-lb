// merge two sorted linked lists

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

void printList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node* solve(Node* head1, Node* head2){

    // if there is only one node in the first list then head1->next will be nullptr, so it wont enter the while loop and return head1
    if(head1->next == nullptr){
        head1->next = head2;
        return head1;
    }

    Node* prev = head1 ;
    Node* curr = head1->next;
    Node* temp = head2;

    while(curr != nullptr && temp != nullptr){
        if(curr->data <= temp->data){
            prev = curr;
            curr = curr->next;

            if(curr == nullptr){
                prev->next = temp;
                break;  // break out of the curr->data <= temp->data loop but not the while loop
            }
        }
        else{
            prev->next = temp;  // prev points to the temp node
            temp = temp->next;  // temp changes to its next node in the other list
            prev = prev->next;  // prev changes to the temp node
            prev->next = curr;  // prev->next points to the curr node
        }
    }
    return head1;
}

Node *merge(Node* head1, Node* head2)
{
    if(head1 == nullptr)
    {
        return head2;
    }

    if(head2 == nullptr)
    {
        return head1;
    }

   if(head1->data <= head2->data){
    return solve(head1,head2);
   }
   else{
    return solve(head2,head1);
   }
}

int main()
{
    Node *head1 = new Node(1);
    Node *n2 = new Node(3);
    Node *n3 = new Node(5);
    Node *n4 = new Node(7);
    Node *n5 = new Node(9);

    head1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    printList(head1);

    Node* head2 = new Node(2); 
    Node* n6 = new Node(4);
    Node* n7 = new Node(6);
    Node* n8 = new Node(8);
    Node* n9 = new Node(10);

    head2->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    printList(head2);

    Node* head = merge(head1,head2);
    printList(head);

    return 0;
}