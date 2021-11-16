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

class vertebrates:public animals{
    public:
        void print();
        void birds();
        void humans();
};

void vertebrates::print(){

}

void vertebrates::birds(){

}

void vertebrates::humans(){

}

class dinosaurs:public animals{
    public:
        void print();
        void theropods();
        void sauropods();

};

void dinosaurs::print(){
    
}

void dinosaurs::theropods(){

}

void dinosaurs::sauropods(){

}
