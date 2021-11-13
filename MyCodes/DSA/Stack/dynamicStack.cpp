//Creating Dynamic Stack
#include<iostream>
#include<string>
using namespace std;

struct costumer{
    string name;
    long long contact_no;
    string gender;
    int age;
    string costumerID;
    costumer* next;
    costumer* prev;
};

class dynamicStack{
    costumer *head=nullptr, *last;

    public:
        costumer* getCostumer(string name, long long contact_no, string gender, int age, string costumerID);    
        void push(string name, long long contact_no, string gender, int age, string costumerID);
        void pop();
        int lengthOfStack();
        void display();
};

costumer* dynamicStack::getCostumer(string name, long long contact_no, string gender, int age, string costumerID){
    costumer* newCostumer = new costumer;
    newCostumer->name  = name;
    newCostumer->age = age;
    newCostumer->contact_no = contact_no;
    newCostumer->gender = gender;
    newCostumer->costumerID = costumerID;
    newCostumer->next = nullptr;
    newCostumer->prev = nullptr;
    return newCostumer;
}

void dynamicStack::push(string name, long long contact_no, string gender, int age, string costumerID){
    costumer* newCostumer = new costumer;
    newCostumer = getCostumer(name, contact_no,gender , age, costumerID);
    if(head==nullptr){
        head = newCostumer;
        last = newCostumer;
    }
    else{
        newCostumer->prev = last;
        last->next = newCostumer;
        last = newCostumer;
    }
}

void dynamicStack::pop(){
    costumer *pop;
    cout<< "Details of Popped node:\n"<<endl;
    cout<<"\n"<< last->name<<endl;
    cout<<last->contact_no<<endl;
    cout<<last->age<<endl;
    cout<<last->gender<<endl;
    cout<<last->costumerID<<endl;
    
    pop = last;
    last = last->prev;
    delete pop;
}

int dynamicStack::lengthOfStack(){
    costumer *temp = head;
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void dynamicStack::display(){
    costumer *temp=head;
    cout<<"\nStart\n"<<endl;
    while(temp){
        cout<<"\n"<<"Name:\t"<<temp->name<<endl;
        cout<<"Contact_no:\t"<<temp->contact_no<<endl;
        cout<<"Age:\t"<<temp->age<<endl;
        cout<<"Gender:\t"<<temp->gender<<endl;
        cout<<"CostumerrID:\t"<<temp->costumerID<<endl;
        temp = temp->next;
    }
    cout<<"\nEnd"<<endl;
}

int main(){
    dynamicStack obj;
    obj.display();
    obj.push("Maeve", 7800179934, "Female", 17, "#1785643");
    obj.push("Ruby", 7825979910, "Female", 17, "#1702358");
    obj.display();
    int res = obj.lengthOfStack();
    cout<<res<<endl;
}