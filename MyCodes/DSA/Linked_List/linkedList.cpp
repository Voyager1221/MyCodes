#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class linkedList{

Node* Head = nullptr;
Node* Last = nullptr;

public:
    Node* getNode(int data);
    void appendNode(int data);
    void display();
};

Node* linkedList::getNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void linkedList::appendNode(int data){
    Node* newNode = getNode(data);
    if(Head==nullptr){
        Head = newNode;
        Last = newNode;
    }
    else{
        Last->next = newNode;
        Last = newNode;
    }
}

void linkedList::display(){
    Node* itr = Head;
    cout<<"Start->";
    for(;itr!=nullptr; itr = itr->next){
        cout<<itr->data<<"->";
    }
    cout<<"NULL";
}

int main(){
    linkedList obj;
    obj.appendNode(1);
    obj.appendNode(2);
    obj.display();

return 0;
}