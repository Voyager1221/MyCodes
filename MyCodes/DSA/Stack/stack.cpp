// Creating a static Stack
#include <iostream>
using namespace std;
#define MAX 1000

class stack{

    int top, length;

public:

    int arr[MAX];
    stack(int length){
        top = -1;
        this->length = length;
    }

    void push(int value);
    int pop();
    int lengthOfStack();
    bool checkOverflow();
    bool checkUnderflow();
    void display();
};

void stack::push(int value){
    if(!checkOverflow()){
       arr[++top] = value; 
    }    
    else{
        cout<<"Stack Overflow"<<endl;
        cout<<"Code is terminated"<<endl;
        exit(-1);
    }
}

int stack::pop(){
    if(!checkUnderflow()){
        return arr[top--];
    }
}

bool stack::checkOverflow(){
    return  top > length-1;
}

bool stack::checkUnderflow(){
    return top < 0;
}

int stack::lengthOfStack(){
    return top+1;
}

void stack::display(){
    cout<<"Start -> ";
    for(int i=0; i<=top; i++){
        cout<< arr[i]<< " -> ";
    }
    cout<<"End"<<endl;
}

int main(){
    stack Patrick(69);
    Patrick.display();
    Patrick.push(1);
    Patrick.push(420);
    Patrick.push(999);
    Patrick.push(11);
    Patrick.push(666);
    Patrick.display();
    Patrick.pop();
    Patrick.display();
    cout<<Patrick.lengthOfStack()<<endl;
    cout<<Patrick.checkOverflow()<<endl;
    cout<<Patrick.checkUnderflow()<<endl;
}