#include <iostream>
#include "livingThing.cpp"
using namespace std;

class plants: public livingThing{
    public:
        void print();
        void floweringPlants();
        void moss();
};

void plants::print(){
    cout<<"\nPlants are categorized under living things"<<endl;
}

void plants::floweringPlants(){
    cout<<"\nFlowering plants are attractive and are used for beautification"<<endl;
}

void plants::moss(){
    cout<<"\nMoss are plants lacking in true roots. These are generally found in jungles and stagnant water"<<endl;
}