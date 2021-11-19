#include<iostream>
#include "livingThings.cpp"
using namespace std;

class fungi:public livingThing{
    public:
        void print();
        void sacFungi();
        void eomycota();
};

void fungi::print(){
    cout<<"\nFungi are categorized under living things"<<endl;
}

void fungi::sacFungi(){
    cout<<"\nSac Fungi includes morels, truffles, brewer's yeast and baker's yeast"<<endl;
}

void fungi::eomycota(){
    cout<<"\nEomycota includes pezizales, cladosporium and halotiales"<<endl;
}