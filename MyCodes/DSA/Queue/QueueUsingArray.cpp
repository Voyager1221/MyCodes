#include <iostream>
using namespace std;

class QueueUsingArray{
public:
    int * queue;
    int front, rear;
    int queueSize;

    QueueUsingArray(int queueSize){
        queue = new int[queueSize]; 
        this->queueSize = queueSize;
        front = -1;
        rear = -1;
        
    }

    void enQueue(int info);
    int deQueue();
    int peek();
    int getSize();
    bool isEmpty();
    bool isFull();
    void displayQueue();
};

void QueueUsingArray::enQueue(int info){
    if(isFull()){
        cout<<"\nArray is full."<<endl;
        cout<<"Terminating the code..."<<endl;
        exit(-1);
    }
    if(front==-1){
            front++;
        }
    queue[++rear] = info;
}

int QueueUsingArray::deQueue(){
    if(isEmpty()){
        cout<<"\nArray is Empty."<<endl;
        cout<<"Terminating the code..."<<endl;
        exit(-1);
    }
    int item = queue[front]; 
    front++;
    return item;
}

int QueueUsingArray::peek(){
    if(isEmpty()){
        cout<<"\nArray is Empty."<<endl;
        cout<<"Terminating the code..."<<endl;
        exit(-1);
    }
    return queue[front]; 
}

int QueueUsingArray::getSize(){
    return rear-front+1;
}

bool QueueUsingArray::isEmpty(){
    return front > rear;
}

bool QueueUsingArray::isFull(){
    return rear > queueSize-1;
}

void QueueUsingArray::displayQueue(){
    if(isEmpty()){
        cout<<"\nThe Queue is empty."<<endl;
        cout<<"\nTerminating the code..."<<endl;
        exit(-1);
    }
    cout<<"Front -> ";
    for(int i=front; i<=rear; i++){
        cout<<queue[i]<<" ";
    }
    cout<<"-> End"<<endl;
}

int menu(){
    cout<<"\nFunctions applicable to Queue..."<<endl;
    cout<<"1]  enQueue."<<endl;
    cout<<"2]  deQueue."<<endl;
    cout<<"3]  peek."<<endl;
    cout<<"4]  get size of queue"<<endl;
    cout<<"5]  Check Empty."<<endl;
    cout<<"6]  Check Full."<<endl;
    cout<<"7]  Display the Queue"<<endl;
    cout<<"8]  Exit."<<endl;

    int ch;
    cout<<"\nEnter the choice : ";
    cin>>ch;
    return ch;
}

void switchForQueue(QueueUsingArray obj){
    int num;
    bool res;
    while(true){
        switch(menu()){
            case 1:
                cout<<"\nEnter the value of item : ";
                cin >> num;
                obj.enQueue(num);
                break;
        
            case 2:
                num = obj.deQueue();
                cout<<"\nThe deQueued item is : "<< num << endl;
                break;

            case 3:
                num = obj.peek();
                cout<<"\nItem in front is : "<< num << endl;
                break;
        
            case 4:
                num = obj.getSize();
                cout<<"\nThe size of the queue is : "<< num <<endl;
                break;
    
            case 5:
                res = obj.isEmpty();
                cout<<"\nIs the queue empty : " << res << endl;
                break;

            case 6:
                res = obj.isFull();
                cout<<"\nIs the queue full : " << res << endl;
                break;    

            case 7:
                obj.displayQueue();
                break;

            case 8:
                cout<<"\nExiting the code..."<<endl;
                exit(0);
        
            default:
                cout<<"\nInvalid choice."<<endl;
        }
    }
}

int main(){

    int size;
    cout<<"\nEnter the size of Queue : ";
    cin>>size;
    QueueUsingArray patrick(size);
    switchForQueue(patrick);
}
