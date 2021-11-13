#include <iostream>
using namespace std;

class CircularQueueUsingArray{
    public:
        int *queue;
        int front;
        int rear;
        int queueLength;
        int count;

        CircularQueueUsingArray(int length){
            queue = new int[length];
            front = 0;
            rear = -1;
            queueLength = length;
            count = 0;
        }

        void enQueue(int info);
        int deQueue();
        int peek();
        int getLength();
        bool isEmpty();
        bool isFull();
        void displayCircularQueue();
};

void CircularQueueUsingArray::enQueue(int info){
    if(isFull()){
        cout<<"\nThe queue is full."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    rear = (++rear)%(queueLength);
    queue[rear] = info;
    count++;
}

int CircularQueueUsingArray::deQueue(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    int item = queue[front];
    front = (++front)%queueLength;
    count--;
    return item;
}

int CircularQueueUsingArray::peek(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    front = (front)%queueLength;
    return queue[front];
}

bool CircularQueueUsingArray::isEmpty(){
    return count<=0;
}

bool CircularQueueUsingArray::isFull(){
    return count>queueLength-1;
}

int CircularQueueUsingArray::getLength(){
    return count+1;
}

void CircularQueueUsingArray::displayCircularQueue(){
    cout<<"Front-> ";
    for(int i=front;i<front+count; i++){
        i = i%queueLength;
        cout<<queue[i]<<"-> ";
    }
    cout<<"End"<<endl;
}


int menu(){
    cout<<"\nFunctions applicable for queue."<<endl;
    cout<<"1]  enQueue."<<endl;
    cout<<"2]  deQueue."<<endl;
    cout<<"3]  peek."<<endl;
    cout<<"4]  isEmpty."<<endl;
    cout<<"5]  isFull."<<endl;
    cout<<"6]  getLength."<<endl;
    cout<<"7]  Display at Circular Queue."<<endl;
    cout<<"8]  exit."<<endl;

    int ch;
    cout<<"Enter the choice : ";
    cin>>ch;
    return ch;
}

void switchCircular(CircularQueueUsingArray obj){
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
                res = obj.isFull();
                cout<<"\nIs the queue full : "<<res<<endl;
                break;
            
            case 6:
                num = obj.getLength();
                cout<<"\nThe length of queue is : "<< num <<endl;
                break;
            
            case 7:
                obj.displayCircularQueue();
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
    int length;
    cout<<"Enter the length of queue : ";
    cin>>length;

    CircularQueueUsingArray Patrick(length);
    switchCircular(Patrick);
}