#include <iostream>
using namespace std;

struct node{
    int node_data;
    node* node_address;
};

void printNode(node* add){
    cout<<"data: "<<add->node_data<<endl;
    cout<<"address: "<<add->node_address<<endl; 
}

int main(){
    node* newNode = new node;
    newNode->node_data = 11;
    newNode->node_address = nullptr;
    printNode(newNode);
}