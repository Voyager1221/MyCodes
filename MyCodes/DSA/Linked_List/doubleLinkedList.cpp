#include <iostream>
#include <string>
using namespace std;

struct Song{
    string name;
    string album;
    string singer;
    float rating;
    int year;
    Song* next;
    Song* prev;
};

class doubleLinkedList{
    Song* Head = nullptr;
    Song* Last = nullptr;

public:
    Song* getNode(string name, string album, string singer, float rating, int year);
    void appendNode(string name , string album, string singer, float rating, int year);
    void insertNode(int pos, string name, string album, string singer, float rating, int year);
    void deleteNode(int pos);
    int lengthLL();
    void displayLL();
};

Song* doubleLinkedList::getNode(string name, string album, string singer, float rating, int year){
    Song* newNode = new Song;
    newNode->name = name;
    newNode->album = album;
    newNode->singer = singer;
    newNode->rating = rating;
    newNode->year = year;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void doubleLinkedList::appendNode(string name, string album, string singer, float rating, int year){
    Song* newNode = getNode(name, album, singer, rating, year);
    if(Head==nullptr){
        Head = newNode;
        Last = newNode;        
    }
    else{
        newNode->prev = Last;
        Last->next = newNode;
        Last = newNode;
    }
}

void doubleLinkedList::insertNode(int pos, string name, string album, string singer, float rating, int year){
    Song* newNode = getNode(name, album, singer, rating, year);
    Song* temp = Head;
    if(pos==lengthLL()){
        newNode->prev = Last;
        Last->next = newNode;
        Last = newNode;
    }
    else if(pos==1){
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
    else{
        while(--pos>1){
            temp = temp->next;
        }
    
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode; 
    }
}

int doubleLinkedList::lengthLL(){
    Song* itr = Head;
    int cnt = 0;
    while(itr){
        itr = itr->next;
        cnt++;
    }
    return cnt;
}

void doubleLinkedList::deleteNode(int pos){
    Song *temp = Head, *del;
    if(pos == lengthLL()){
        del = Last;
        Last = Last-> prev;
        Last->next = nullptr;
        delete del;
    }
    else if(pos==1){
        del = Head;
        Head = Head->next;
        Head->prev = nullptr;
        delete del;
    }
    else{
        while(--pos>1){
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        delete del; 
        
    }
}

void doubleLinkedList::displayLL(){
    Song* itr = Head;
    cout<<"\nElements of Dynamic Array or Linked List are:"<<endl;
    for(;itr!=nullptr; itr = itr->next){
        cout<<"\nSong name: "<< itr->name<<endl;
        cout<<"Album name: "<< itr->album<<endl;
        cout<<"Singer: "<< itr->singer<<endl;
        cout<<"Rating: "<< itr->rating<<endl;
        cout<<"Year: "<< itr->year<<endl;
        cout<<endl;
    }
    cout<<"END"<<endl;
}

int main(){
    doubleLinkedList Patrick;
    Patrick.appendNode("Temperature", "Temp", "Sean Paul", 8.5, 2009);
    Patrick.appendNode("8TEEN", "Location", "Khalid", 7.8, 2019);
    Patrick.appendNode("NeverMind", "NevaMai", "Dennis Loyd", 7.8, 2018);
    Patrick.insertNode(2, "Best of Me", "Neffex", "Neffex Band", 9.3, 2017);
    Patrick.displayLL();
    Patrick.deleteNode(1);
    Patrick.displayLL();
    Patrick.appendNode("Temperature", "Temp", "Sean Paul", 8.5, 2009);
    Patrick.displayLL();
    Patrick.deleteNode(4);
    Patrick.displayLL();
    Patrick.insertNode(1, "Temperature", "Temp", "Sean Paul", 8.5, 2009);
    Patrick.displayLL();
}

