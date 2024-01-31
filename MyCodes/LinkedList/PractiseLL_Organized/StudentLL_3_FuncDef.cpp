#include <iostream>
#include "StudentLL_3.h"
#include <chrono>

using namespace std;

Student* StudentLinkedList_Practise::createNode(string name, int uid, int age){
    // Allocating memory to a node
    Student* newNode = new Student;

    // Initializing the default pointer address as nullptr
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Storing the data of a student in the newly created node.
    newNode->studData.name = name;
    newNode->studData.uid = uid;
    newNode->studData.age = age;

    return newNode;
}

void StudentLinkedList_Practise::appendNode(string name, int uid, int age){
    // Creating a new node
    Student* newNode = createNode(name, uid, age);

    // Linking the nodes
    // Initiating the linkedlist if the node is created for the first time
    if(head==nullptr){
        head = newNode;
    }
    // Linking the nodes by updating the address pointers 
    else{
        newNode->prev = last;
        last->next = newNode;
    }
    // After the linking is completed, the address pointer of last will be updated to newNode
    last = newNode; 
}

Student* StudentLinkedList_Practise::traverseLL(int endPosition){
    Student* temp = head;
    // Traversing LL till the target node
    while(endPosition-->1){
        temp = temp->next;
    }
    return temp;
}

void StudentLinkedList_Practise::addNode(int pos, string name, int uid, int age){
    // In case of insertion of node, we will traverse till just one node before target position
    Student* penultimateTargetNode = traverseLL(pos-1);
    Student* newNode = createNode(name, uid, age);

    // If the target position is 1st Node
    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // Every other target positions except 1st and last Node
    else{
        newNode->prev = penultimateTargetNode;
        newNode->next = penultimateTargetNode->next;
        // newNode->next->prev = newNode;
        penultimateTargetNode->next->prev = newNode;
        penultimateTargetNode->next = newNode;
    }

    // Assumption: We are not adding node at the last position using addNode()
    // For that use case we have appendNode()

}

int StudentLinkedList_Practise::sizeOfLL(){
    Student* temp = head;
    int lenOfLL = 0;

    while(temp!=nullptr){
        temp = temp->next;
        lenOfLL++;
    }
    return lenOfLL;
}

void StudentLinkedList_Practise::delNode(int pos){
    Student* targetNode = traverseLL(pos);

    // If the target node is head Node
    if(pos == 1){
        head->next->prev = nullptr;
        head = head->next;
        delete targetNode;
    }
    // If the target node is last Node
    else if(pos == sizeOfLL()){
        targetNode->prev->next = nullptr;
        last = targetNode->prev;
        delete targetNode;
    }
    // If the target node is in-between Nodes
    else{
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev=  targetNode->prev;
        delete targetNode;
    }
}

void StudentLinkedList_Practise::display(){
    Student* temp = head;
    int pos = 1;
    cout<< "\tPosition: \tName \t\tRoll \tAge \n" <<endl;

    while(temp){
        cout<<"\n\t"<<pos;
        cout<<" \t --> ";

        cout<<" \t "<<temp->studData.name;
        cout<<" \t "<<temp->studData.uid;
        cout<<" \t "<<temp->studData.age;
        temp = temp->next;
        pos++;
    }
}

void StudentLinkedList_Practise::displayMenu(){
    // int ch;
    cout<<"\nEnter:"
    "\n1.\tTo append node to dynamic linked list."
    "\n2.\tTo add node at target position."
    "\n3.\tTo delete node at target position."
    "\n4.\tTo print the length of dynamic linked list."
    "\n5.\tTo display the dynamic linked list."
    "\n6.\tTo exit the code.";
    cout<<"\nEnter the choice: ";

    // cin>>ch;
    // return ch;
}

void StudentLinkedList_Practise::createDynamicLL(){
    
    while(true){

        int ch=0;
        displayMenu();
        
        if(!(cin>>ch)){
            cout<<"Invalid input. Please enter an integer input."<<endl;
            // Clear the error flag
            cin.clear();
            // Discarding the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            int pos, uid, age;
            string name;
            switch(ch){
                case 1:
                    cout<<"Enter name, uid and age respectively: "<<endl;
                    cin>>name>>uid>>age;
                    
                    this->appendNode(name, uid, age);
                    
                    break;

                case 2:
                    cout<<"Enter position, name, uid and age respectively: "<<endl;
                    cin>>pos>>name>>uid>>age;
                    
                    this->addNode(pos, name, uid, age);
                    
                    break;

                case 3:
                    cout<<"Enter the postion of the node to be deleted: ";
                    cin>>pos;
                    this->delNode(pos);

                    break;

                case 4:
                    cout<< "The length of dynamic linked list is: " << this->sizeOfLL() <<endl;
                
                    break;
                
                case 5:
                    this->display();
                    chrono::seconds(2);

                    break;

                
                
                case 6:
                    cout<<"Terminating the code ..."<<endl;
                    exit(0);
                
                default:
                    cout<<"Please enter valid inputs ..."<<endl;

                    break;
            }
        }
    
    }
}

