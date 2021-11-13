#include <iostream>
//#include <string>
using namespace std;

template<class T>
struct Node{
    T info;
    Node<T>* next;
};

template <class T>
class GenericQueueUsingCircularLL{
    public:
        Node<T> *front;
        Node<T> *rear;
        int count;

        GenericQueueUsingCircularLL(){
            front = nullptr;
            rear = nullptr;
            count = 0;
        }

        Node<T>* getNode(T info);
        void enQueue(T info);
        T deQueue();
        T peek();
        bool isEmpty();
        int getLength();
        void display();

};

template<class T>
Node<T>* GenericQueueUsingCircularLL<T>::getNode(T info){
    Node<T>*newNode = new Node<T>;
    newNode->info = info;
    newNode->next = nullptr;

    return newNode;
}

template <class T>
void GenericQueueUsingCircularLL<T>::enQueue(T info){

    Node<T> *newNode = getNode(info);
    if(front==nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

template <class T>
T GenericQueueUsingCircularLL<T>::deQueue(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    T item = front->info;
    Node<T> *del = front;
    front = front->next; 
    rear->next = front;
    count--;
    delete del;
    return item;    
}


template <class T>
T GenericQueueUsingCircularLL<T>::peek(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
    return front->info;    
}

template <class T>
int GenericQueueUsingCircularLL<T>::getLength(){
    return count;    
}

template <class T>
bool GenericQueueUsingCircularLL<T>::isEmpty(){
    return count<=0;
}

template <class T>
void GenericQueueUsingCircularLL<T>::display(){
    if(isEmpty()){
        cout<<"\nThe queue is empty."<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }    
    Node<T> *traverse = front;
    int tick = count;
    cout<<"\nFront-> ";
    while(tick--){
        cout<<traverse->info<<"-> ";
        traverse = traverse->next;
    }
    cout<<"End"<<endl;
}

int menu(){
    cout<<"\nFunctions applicable to Queue..."<<endl;
    cout<<"1]  enQueue."<<endl;
    cout<<"2]  deQueue."<<endl;
    cout<<"3]  peek."<<endl;
    cout<<"4]  get size of queue"<<endl;
    cout<<"5]  Check Empty."<<endl;
    cout<<"6]  Display the Queue"<<endl;
    cout<<"7]  Exit."<<endl;

    int ch;
    cout<<"\nEnter the choice : ";
    cin>>ch;
    return ch;        
}

template <class T>
void switchForGenericQueue(GenericQueueUsingCircularLL<T> obj){
    T num;
    int n;
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
                n = obj.getLength();
                cout<<"\nThe size of the queue is : "<< n <<endl;
                break;
    
            case 5:
                res = obj.isEmpty();
                cout<<"\nIs the queue empty : " << res << endl;
                break;

            case 6:
                obj.display();
                break;

            case 7:
                cout<<"\nExiting the code..."<<endl;
                exit(0);
        
            default:
                cout<<"\nInvalid choice."<<endl;
                exit(-1);
        }
    }
}

int main(){
    //GenericQueueUsingCircularLL<int> Patrick;
    //GenericQueueUsingCircularLL<float> Patrick;
    //GenericQueueUsingCircularLL<char> Patrick;
    GenericQueueUsingCircularLL<string> Patrick;
    switchForGenericQueue(Patrick);
}
