#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int ele);
};

Node::Node(int ele){
    data = ele;
    next = NULL;
}

class LinkedList{
    public:
        LinkedList();
        Node* insertNode(Node* head,int ele);
        Node* deleteNodeGivenKey(Node* head,int key);
        Node* deleteNodeGivenPosition(Node* head,int position);
        void printList(Node* head);
};

LinkedList::LinkedList(){

}

Node* LinkedList::insertNode(Node* head,int ele){
    /// If head is null create new node
    /// if head is not null then create new node and assign its address to next of head
    if(head == NULL){
        return new Node(ele);
    }
    head->next = insertNode(head->next,ele);
    return head;
}

Node* LinkedList::deleteNodeGivenKey(Node* head,int key){
    /// if head contains key then head is to be deleted
    /// when key is found assign the next of the current node to next of previous node
    Node* tmp = head,*prev;
    if(tmp != NULL && tmp->data == key){
        head = tmp->next;
        return head;
    }

    while(tmp != NULL && tmp->data != key){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return head;
    }
    prev->next = tmp->next;
    return head;
}

Node* LinkedList::deleteNodeGivenPosition(Node* head,int position){
    Node* tmp = head,*prev;
    if(position == 0){
        head = tmp->next;
        return head;
    }

    int index = 0;
    while(tmp != NULL && index != position){
        prev = tmp;
        tmp = tmp->next;
        index++;
    }
    if(tmp == NULL){
        return head;
    }
    prev->next = tmp->next;
    return head;
}

void LinkedList::printList(Node* head){
    ///print the elements of the list
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    LinkedList* l = new LinkedList();
    int x,y;
    cout<<"Elements to be inserted : "<<endl;
    for(int i=1;i<=5;i++){
        cin>>x;
        head = l->insertNode(head,x);
    }
    cout<<"Linked List before deletion: ";
    l->printList(head);
    cout<<endl;
    cout<<"Element to be deleted : Enter key "<<endl;
    cin>>y;
    head = l->deleteNodeGivenKey(head,y);
    cout<<"Linked List after key based deletion: ";
    l->printList(head);
    cout<<endl;
    cout<<"Element to be deleted : Enter position "<<endl;
    cin>>y;
    head = l->deleteNodeGivenPosition(head,y);
    cout<<"Linked List after position based deletion: ";
    l->printList(head);
return 0;
}
