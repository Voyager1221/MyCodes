#include <iostream>
#include <chrono>
using namespace std;

struct Student{
    struct Data{
    string name;
    int roll;
    int age;
    }data;

    Data studData;
    Student *next;
    Student *prev;
};

class StudentLinkedList{
    Student *head = nullptr;
    Student *last = nullptr;

    public:

    Student *getNode(string name, int roll, int age);
    void appendNode(string name, int roll, int age);
    void addNode(int pos, string name, int roll, int age);
    int sizeOfDLL();
    void delNode(int pos);
    void display();
};

Student* StudentLinkedList::getNode(string name, int roll, int age){
    Student* newNode = new Student;
    // newNode = new Student;
    cout << "Printing the size of the string-object, name: " << sizeof(name) <<" bytes."<<endl;
    // for(int i=0; i<sizeof(name); i++){
    //     newNode->studData.name[i] = name[i];
    // }
    newNode->studData.name = name;
    newNode->studData.roll = roll;
    newNode->studData.age = age;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void StudentLinkedList::appendNode(string name, int roll, int age){
    Student* newNode = getNode(name, roll, age);
    if(head==nullptr){
        head = newNode;
    }
    else{
        newNode->prev = last;
        last->next = newNode;
    }
    last = newNode;
}

int StudentLinkedList::sizeOfDLL(){
    Student* temp = head;
    int cnt = 0;

    while(temp!=nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void StudentLinkedList::addNode(int pos, string name, int roll, int age){
    Student* newNode = getNode(name, roll, age);
    
    if(pos==1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else{
        Student* temp = head;
        while(--pos>1){
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void StudentLinkedList::delNode(int pos){
    Student* temp = nullptr;
    if(pos == 1){
        
        temp = head;
        head = head->next;
        delete temp;
    
    }else if (pos == sizeOfDLL()){
        
        last->prev->next = nullptr;
        temp = last;
        last = last->prev;
        delete temp;
    
    }else{
        Student* temp = head;
        while(--pos){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    
    }
}

void StudentLinkedList::display(){
    Student* temp = head;
    int pos = 1;
    cout<< "\tPosition: \tName \t\tRoll \tAge \n" <<endl;
    
    while(temp){
        cout<<"\t "<<pos;
        cout<<" \t--> ";
    
        string studName = temp->studData.name;
        // I don't know why I took this approach previously. This approach led to issue with storing names of student object.
        // for(int i=0; i<sizeof(name)-1; i++){
        //     cout<<temp->studData.name[i];
        // } 
        cout<<" \t "<<studName;
        cout<<" \t " << temp->studData.roll;
        cout<<" \t " << temp->studData.age <<endl;
        temp = temp->next;
        pos++;
    }
}

int menu(){
    int ch;
    cout<<"\nEnter:"
    "\n1.\tTo append node to linked list."
    "\n2.\tTo add node at target position."
    "\n3.\tTo delete node at target position."
    "\n4.\tTo display the linked list."
    "\n5.\tTo exit the code.";
    cout<<"\nEnter the choice: ";

    cin>>ch;
    return ch;
}

int main(){
    int roll, age, pos;
    string name;
    StudentLinkedList obj1;
    while(true){
        
        int ch = 0; // Initializing ch = 0, to avoid any sort of issues, as in failure of expected input data-type the compiler retains the initial value of the variable. 
        ch = menu();
        cout<<"Printing the value of choice, ch: "<<ch<<endl;
        if(!ch){
            cout<<"Invalid input. Please enter an integer."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discarding the input buffer
        }else{
            switch(ch){
                case 1:
                    cout<<"Enter name, roll and age respectively: "<<endl;
                    cin>>name>>roll>>age;
                    cout<<"Printing the studentName entered as input: "<<name<<endl;
                    obj1.appendNode(name, roll, age);
                    break;

                case 2:
                    cout<<"Enter position, name, roll and age respectively: "<<endl;
                    cin>>pos>>name>>roll>>age;
                    obj1.addNode(pos, name, roll, age);
                    break;

                case 3:
                    cout<<"Enter the postion of the node to be deleted: ";
                    cin>>pos;
                    obj1.delNode(pos);
                    break;    

                case 4:
                    obj1.display();
                    chrono::seconds(2);
                    break;

                
                case 5:
                    cout<<"Terminating the code ..."<<endl;
                    exit(0);


                default:
                    cout<<"Please enter valid inputs ..."<<endl;
                    break;
            }
        }
    }
    return 0;
}