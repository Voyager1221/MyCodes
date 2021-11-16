#include <iostream>
#include "livingThings.cpp"
using namespace std;

class animals : public livingThings{
    public:
        void print();
        void vertebrates();
        void dinosaurs();
};

void animals::print(){
    cout<<"\nAnimals are categorized into vertebrates and dinosaurs"<<endl;
}

void animals::vertebrates(){
    cout<<"\nAny animal of the chordate subphylum vertebrata"<<endl;
}

void animals::dinosaurs(){
    cout<<"\nDinosaurs are a diverse group of reptiles of clade dinosauria"<<endl;
}

