#ifndef STUDENTLL_3_H
#define STUDENTLL_3_H

#include <string>

struct studentData{
    std::string name;
    int uid;
    int age;
};

struct Student{
    studentData studData;
    Student* prev;
    Student* next;
};
class StudentLinkedList_Practise{

public:
    // Constructor definition
    // StudentLinkedList_Practise();

    // Member function declaration
    Student* createNode(std::string name, int uid, int age);
    void appendNode(std::string name, int uid, int age);
    void addNode(int pos, std::string name, int uid, int age);
    void delNode(int pos);
    
    Student* traverseLL(int endPosition);
    int sizeOfLL();
    
    void display();
    void displayMenu();
    void createDynamicLL();

    // Member variables
    Student* head = nullptr;
    Student* last = nullptr;
};

#endif