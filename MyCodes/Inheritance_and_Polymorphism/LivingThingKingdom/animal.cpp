#include <iostream>
#include "livingThing.cpp"
using namespace std;

class animal : public livingThing{
    public:
        void print();
        void vertebrates();
        void dinosaurs();
};

void animal::print(){
    cout<<"\nAnimals are categorized into vertebrates and dinosaurs"<<endl;
}

void animal::vertebrates(){
    cout<<"\nAny animal of the chordate subphylum vertebrata"<<endl;
}

void animal::dinosaurs(){
    cout<<"\nDinosaurs are a diverse group of reptiles of clade dinosauria"<<endl;
}

