// check if there are loops in the linked list

#include <iostream>
#include<map>
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
    while(n != nullptr){
        cout << n->data << " " ;
        n = n->next ;
    }
    cout << endl ;
}

bool detectLoop(Node* head){
    if(head == nullptr){
        return false ;
    }

    map<Node*, bool> visited ; 

    Node* temp = head ;
    while(temp != nullptr){
        if(visited[temp]){
            return true ;
        }
        visited[temp] = true ;
        temp = temp->next ;
    }
    return false ;   
}

Node* floydDetectLoop(Node* head){
    if(head == nullptr){
        return NULL ;
    }

    Node* slow = head ;
    Node* fast = head ;

    while(slow != nullptr && fast != nullptr ){
        slow = slow->next ;
        fast = fast->next ;
        if(fast != nullptr){
            fast = fast->next ;
        }

        if(slow == fast){
            return slow ;
        }
    }
    return NULL ;
}

Node* intersectingNode(Node* head){
    if(head == nullptr){
        return NULL ;
    }

    Node* slow = head ;
    Node* intersectingNode = floydDetectLoop(head) ;

    while(slow != intersectingNode){
        slow = slow->next ;
        intersectingNode = intersectingNode->next ;
    }
    return slow ;   
}

void removeLoop(Node* head){
    if(head == nullptr){
        return ;
    }

    Node* Nodeintersection = intersectingNode(head) ;
    if(Nodeintersection == nullptr){
        return ;
    }

    Node* temp = Nodeintersection ;
    while(temp->next != Nodeintersection){
        temp = temp->next ;
    }
    cout << "node with data " << temp->data << " is the last node" << endl ;
    temp->next = nullptr ;
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
    sixth->next = second;

    // cout << detectLoop(head) << endl ;
    // cout << floydDetectLoop(head)->data<< endl ;
    cout << intersectingNode(head)->data << endl ;
    removeLoop(head) ;
    printList(head) ;    

    return 0;
}