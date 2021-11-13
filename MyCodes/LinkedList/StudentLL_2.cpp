#include<iostream>
using namespace std;

struct Student{
    struct Data{
        //char name[50];
        string name;
        int roll;
        int age;
    }data;
    Student* prev;
    Student* next;
};

class StudentLinkedList2{
    Student *head=nullptr;
    Student *last=nullptr;

    public:

    Student* getNode(string name, int roll, int age);
    void addNode(string name, int roll, int age);
    int sizeOfDLL();
    void appendNode(int pos, string name, int roll, int age);
    void delNode(int pos);
    void display();
};

Student* StudentLinkedList2::getNode(string name, int roll, int age){
    Student* newNode;
    newNode = new Student;
    for(int i=0;i<sizeof(name);i++){
        newNode->data.name[i] = name[i];
    }
    newNode->data.roll = roll;
    newNode->data.age = age;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void StudentLinkedList2::addNode(string name,int roll, int age){
    Student *newNode;
    newNode = getNode(name, roll, age);
    if(head==nullptr)
        head = newNode;
    else{
        newNode->prev = last;
        last->next = newNode;
    }
    last = newNode;
}

void StudentLinkedList2::appendNode(int pos, string name, int roll, int age){
    Student *temp, *newNode;
    newNode = getNode(name, roll, age);
    if(pos==sizeOfDLL()){
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    else{
        temp=head;
        while(pos-->2){
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        newNode->next->prev = newNode;
        temp->next = newNode;
    }
}    

int StudentLinkedList2::sizeOfDLL(){
    Student *temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void StudentLinkedList2::delNode(int pos){    
    Student *temp,*del;
    if(pos==sizeOfDLL()){
        del=last;
        del->prev->next = nullptr;
        delete del;
    }
    else{
        temp=head;
        while(pos-->2){
            temp = temp->next;        
        }
        del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        delete del;
    }
}

void StudentLinkedList2::display(){
    Student *temp=head;
    cout<<"The Elements of Linked List are: "<<endl;
    while(temp){
        cout<<"\nName:";
        for(int i=0;i<sizeof(temp->data.name)-1;i++){
            cout<<temp->data.name[i];
        }
        cout<<"\nlength : "<<sizeof(temp->data.name)<<endl;
        cout<<"\tRoll: "<<temp->data.roll;
        cout<<"\tAge: "<<temp->data.age<<endl;
        temp = temp->next;
    }
}

int menu(){
    int ch;
    cout<<"\nEnter:"
    "\n1.\tTo add node to linked list."
    "\n2.\tTo append node at target position."
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
    StudentLinkedList2 obj1;
    while(true){
        switch(menu()){
            case 1:
                cout<<"Enter name, roll and age respectively: "<<endl;
                cin>>name>>roll>>age;
                obj1.addNode(name, roll, age);
                break;

            case 2:
                cout<<"Enter position, name, roll and age respectively: "<<endl;
                cin>>pos>>name>>roll>>age;
                obj1.appendNode(pos, name, roll, age);
                break;

            case 3:
                cout<<"Enter the postion of the node to be deleted: ";
                cin>>pos;
                obj1.delNode(pos);
                break;    

            case 4:
                obj1.display();
                break;

            case 5:
                exit(0);    
        }
    }
    return 0;
}