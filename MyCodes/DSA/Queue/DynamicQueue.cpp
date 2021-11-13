#include <iostream>
using namespace std;

typedef struct n{
    int info;
    n* next;
}Node;

class DynamicQueue{
    public:
        Node *front;
        Node *rear;

        DynamicQueue(){
            front = nullptr;
            rear = nullptr;
        }

        Node* getNode(int info);
        void enQueue(int info);
        int deQueue();
        int peek();
        bool isEmpty();
        int getLength();
        void displayDynamicQueue();
};

Node* DynamicQueue::getNode(int info){
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;

    return newNode;
}

void DynamicQueue::enQueue(int info){

    Node *newNode = getNode(info);
    if(front==nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

int DynamicQueue::deQueue(){
    if(isEmpty()){
        cout<<"\nQueue is Empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    Node *del;
    del = front;
    int item = del->info;
    front  = front->next;
    delete del;
    return item;
}

int DynamicQueue::peek(){
    if(isEmpty()){
        cout<<"\nQueue is Empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    return front->info;
}

bool DynamicQueue::isEmpty(){
    return front==nullptr;
}

int DynamicQueue::getLength(){
    Node *traverse = front;
    int cnt=0;
    while(traverse){
        traverse = traverse->next;
        cnt++;
    }
    return cnt;
}

void DynamicQueue::displayDynamicQueue(){
    Node *traverse = front;
    cout<<"Front-> ";
    for(int i=0; i<getLength(); i++){
        cout<< traverse->info << "-> ";
        traverse = traverse->next;
    }
    cout<<"End"<<endl;
}

int menu(){
    cout<<"\nFuncions applicable on Dynamic Queue.\n"<<endl;
    cout<<"1]  enQueue."<<endl;
    cout<<"2]  deQueue."<<endl;
    cout<<"3]  peek."<<endl;
    cout<<"4]  Check empty."<<endl;
    cout<<"5]  Length of Dynamic Queue "<<endl;
    cout<<"6]  Display the items in Dynamic Queue." <<endl;
    cout<<"7]  Exit."<<endl;

    int ch;
    cout<<"\nEnter the choice : ";
    cin >> ch;
    return ch;
}

void switchDQ(DynamicQueue obj){
    while(true){
        int num;
        bool res;
        switch(menu()){
            case 1:
                cout<<"\nEnter the item to be added : ";
                cin>>num;
                obj.enQueue(num);
                break;

            case 2:
                num = obj.deQueue();
                cout<<"\nThe deQueued item is : "<<num<<endl;
                break;

            case 3:
                num = obj.peek();
                cout<<"\nThe front item is : "<< num <<endl;
                break;
            
            case 4:
                res = obj.isEmpty();
                cout<<"\nIs the Dynamic Queue empty : "<<res<<endl;
                break;

            case 5:
                num = obj.getLength();
                cout<<"\nThe length of the Dynamic Queue is : " << num << endl;
                break;

            case 6:
                obj.displayDynamicQueue();
                break;
            
            case 7:
                cout<<"\nEnding the code..."<<endl;
                exit(0);
            
            default:
                cout<<"\nInvalid choice."<<endl;
        }
    }
}

int main(){
    DynamicQueue Patrick;

    switchDQ(Patrick);
}