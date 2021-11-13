#include <iostream>
using namespace std;

typedef struct n{
    int info;
    n* next;
}Node;

class CircularQueueLL{
    public:
      Node* front;
      Node* rear;
      int count;

      CircularQueueLL(){
          front = nullptr;
          rear = nullptr;
          count = 0;
      }  
    
      Node* getNode(int info);
      void enQueue(int info);
      int deQueue();
      int peek();
      bool isEmpty();
      int getLength();
      void displayCircularQueueLL();
}; 

Node* CircularQueueLL::getNode(int info){
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;
    return newNode;
}

void CircularQueueLL::enQueue(int info){
    Node* newNode;
    newNode = getNode(info);
    if(front==nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    count++;
}

int CircularQueueLL::deQueue(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    int item = front->info;
    Node* del = front;
    front = front->next;
    rear->next = front;
    count--;
    delete del;
    return item;
}

int CircularQueueLL::peek(){
    int item;
    item = front->info;
    return item;
}

int CircularQueueLL::getLength(){
    return count;
}

bool CircularQueueLL::isEmpty(){
    return count<=0;
}

void CircularQueueLL::displayCircularQueueLL(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    Node* traverse = front;
    int tick = count;
    cout<<"Front-> ";
    while(tick--){
        cout<<traverse->info<< "-> ";
        traverse = traverse->next;
    }
    cout<<"End"<<endl;
}

int menu(){
    cout<<"\nFunctions applicable for queue."<<endl;
    cout<<"1]  enQueue."<<endl;
    cout<<"2]  deQueue."<<endl;
    cout<<"3]  peek."<<endl;
    cout<<"4]  isEmpty."<<endl;
    cout<<"5]  getLength."<<endl;
    cout<<"6]  Display the Dynamic Circular Queue."<<endl;
    cout<<"7]  exit."<<endl;

    int ch;
    cout<<"Enter the choice : ";
    cin>>ch;
    return ch;
}

void switchCircularLL(CircularQueueLL obj){
    while(true){
        int num;
        bool res;
        switch(menu()){
            case 1:
                cout<<"\nEnter the value of item : ";
                cin>>num;
                obj.enQueue(num);
                break;

            case 2:
                num = obj.deQueue();
                cout<<"\nThe deQueued item is : "<< num <<endl;
                break;

            case 3:
                num = obj.peek();
                cout<<"\nThe front item is : "<< num <<endl;
                break;

            case 4:
                res = obj.isEmpty();
                cout<<"\nIs the queue empty : "<<res<<endl;
                break;

            case 5:
                num = obj.getLength();
                cout<<"\nThe length of queue is : "<< num <<endl;
                break;
            
            case 6:
                obj.displayCircularQueueLL();
                break;

            case 7:
                cout<<"\nExiting the code..."<<endl;
                exit(0);

            default:
                cout<<"\nInvalid choice."<<endl;
        }
    }
}

int main(){
    CircularQueueLL Patrick;
    switchCircularLL(Patrick);
    return 0;
}