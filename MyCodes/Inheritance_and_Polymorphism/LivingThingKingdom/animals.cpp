#include <iostream>
#include "livingThings.cpp"
using namespace std;

class animals : public livingThing{
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

class vertebrates:public animals{
    public:
        void print();
        void birds();
        void humans();
};

void vertebrates::print(){
    cout<<"\nVertebrates comes under animals"<<endl;
}

void vertebrates::birds(){
    cout<<"\nBirds comes under vertebrates"<<endl;
}

void vertebrates::humans(){
    cout<<"\nAnimals comes under vertebrates"<<endl;
}

class dinosaurs:public animals{
    public:
        void print();
        void theropods();
        void sauropods();

};

void dinosaurs::print(){
    cout<<"\nDinosaurs come under animals"<<endl;
}

void dinosaurs::theropods(){
    cout<<"\nTheropods were most diverse group of saurischian dinosaurs"<<endl;
}

void dinosaurs::sauropods(){
    cout<<"\nSauropods is a clade of saurischian dinosaurs"<<endl;
}
