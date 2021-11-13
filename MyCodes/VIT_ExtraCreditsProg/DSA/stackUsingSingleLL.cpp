/*
Q2. Write a program to implement stack of float numbers using singly simple link list.
Use dynamic memory allocation.
The Node structure is given here use same structure in this program.

typedef struct N{
    int info;
    N* next;
}Node;

*/

#include <iostream>
using namespace std;

typedef struct N{   //Defining structure for the node of dynamic stack
    float info;
    N* next;
}Node;

class stackUsingSingleLL{
    Node* head = nullptr;

    //Declaring the function that have public access
    public:                         
        Node* getNode(float info);
        void pushNode(float info);
        float popNode();
        float peek();
        bool isUnderflow();
        int length();
        void displayStack();
};

//getNode is used for memory allocation
//Also some of the values are initialized
Node* stackUsingSingleLL::getNode(float info){
     Node* newNode = new Node;
     newNode->info = info;
     newNode->next = nullptr;    
}

//pushNode appends node for stack by linking nodes
void stackUsingSingleLL::pushNode(float info){
    Node* newNode = getNode(info);
    if(head==nullptr){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

//Checking state of stack
bool stackUsingSingleLL::isUnderflow(){
    return head==nullptr;   //Head = nullptr determines the stack is empty
}

float stackUsingSingleLL::popNode(){
    Node* del;
    float deleted_val;
    if(!isUnderflow()){     //Checking if popping can be performed or not
        del = head;
        deleted_val = del->info;
        head = head->next;
        delete del;         //Deleting unpointed/unwanted memory
        return deleted_val;
    }
    else{       //Terminating the code when further popping cannot be performed 
        cout<<"Stack Underflow"<<endl;
        cout<<"Terminating the code."<<endl;
        exit(-1);
    }
}

//To see the last element in stack
float stackUsingSingleLL::peek(){
    return head->info;
}


//Finding the length by traversing the whole list
int stackUsingSingleLL::length(){
    Node* traverseLL = head;
    int cnt = 0;
    if(!isUnderflow()){
        while(traverseLL){
            traverseLL = traverseLL->next;
            cnt++;
        }
        return cnt;
    }
    else{
        cout<< "Stack Underflow" <<endl;
        cout<< "Terminating the code." <<endl;
        exit(-1);
    }
}
//Displaying the stack in LIFO form
void stackUsingSingleLL::displayStack(){
    Node* traverseLL = head;
    if(!isUnderflow()){
        cout<< "\nStart -> ";
        while(traverseLL){
            cout<< traverseLL->info << " -> ";
            traverseLL = traverseLL->next;
        }
        cout<< "End\n" << endl;
    }
}

//Menu for user to perform operations
int menu(){
    cout<< "\nProgram Funtions:\n"<< endl;
    cout<< "1.  Push value." << endl;
    cout<< "2.  Pop value." << endl;
    cout<< "3.  Peek." << endl;
    cout<< "4.  Check Underflow." << endl;
    cout<< "5.  Length of stack." << endl;
    cout<< "6.  Display the stack from top to bottom." << endl;
    cout<< "7.  Exit.\n" << endl;

    int ch;
    cout<< "Enter the choice: ";
    cin>> ch;   //Taking choice from user

    return ch;
}

//Function to be operated is determined here
void switchCase(stackUsingSingleLL obj){
    while(true){
        float num;
        switch(menu()){
        case 1:
            cout<< "Enter the value : ";
            cin >> num;
            obj.pushNode(num);
            break;

        case 2:
            num = obj.popNode();
            cout << "The popped value is : " << num << endl;
            break;

        case 3:
            num = obj.peek();
            cout << "Last element of the stack is : " << num << endl;
            break;

        case 4:
            bool result;
            result = obj.isUnderflow();
            cout << "Is Stack underflow : " << result << endl;
            break;

        case 5:
            num = obj.length();
            cout<< "The length of stack is : " << int(num) << endl;
            break;

        case 6:
            obj.displayStack();    
            break;

        case 7:
            cout<< "Ending the code..." << endl;
            exit(0);

        default:    //Invalid choices are handled here
            cout<< "\nThe choice opted isn't available." << endl;
    }
    }
}

int main(){
    /*Creating object of the class
      So that the member function of class can be accessed*/
    stackUsingSingleLL obj;
    //Entry point
    switchCase(obj);
    return 0;
}