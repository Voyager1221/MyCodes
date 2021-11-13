#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* npx;
};

class XOR_LL{
Node *head = nullptr;
Node *last = nullptr;
public:
    Node* createNode(int data);
    void createLL(int data);
    Node* XOR_Converter(Node*add1, Node*add2);
    void Display();
};


Node* XOR_LL::createNode(int data){
    Node * newNode;
    newNode = new Node;
    newNode->data = data;
    newNode->npx = NULL;
    return newNode;
}

void XOR_LL::createLL(int data){
    Node *newNode,*temp=head; 
    newNode = createNode(data);
    newNode->data = data;
    newNode->npx = XOR_Converter(temp, NULL);
    if(temp!=NULL){
        Node* prev = XOR_Converter(temp->npx,NULL); 
        temp->npx = XOR_Converter(newNode, prev);
    }
    temp = newNode;
    last = newNode;
}


Node* XOR_LL::XOR_Converter(Node*add1, Node*add2){
    //cout<<(Node*) ((uintptr_t)(add1)^(uintptr_t)(add2))<<endl;
    return (Node*)((uintptr_t)(add1)^(uintptr_t)(add2));
}

void XOR_LL::Display(){
    Node *temp = head,*prev=NULL,*next;
    while(temp){
         
        cout<<temp->data<<"->";
        next = XOR_Converter(prev, temp->npx);
        prev = temp;
        temp = next;
    }
    cout<<"END"<<endl;
}

int main(){
    XOR_LL obj;
    obj.createLL(1);
    obj.createLL(2);
    obj.createLL(3);
    obj.createLL(4);
    obj.Display();
    return 0;
}