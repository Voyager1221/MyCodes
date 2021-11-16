#include <iostream>
#include "livingThings.cpp"
using namespace std;

class plants: public livingThings{
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

class floweringPlants: public plants{
    public:
        void print();
        void lily();
        void daisy();
};

void floweringPlants::print(){
    cout<<"\nFlowering plants comes under plants"<<endl;
}

void floweringPlants::lily(){
    cout<<"\nLilies looks best when planted in cluster of three or more bulbs"<<endl;
}

void floweringPlants::daisy(){
    cout<<"\nDaisies are often used to symbolize purity and innocence"<<endl;
}

class moss:public plants{
    public:
        void print();
        void spaghnales();
        void polytrichaceae();
};

void moss::print(){
    cout<<"\nMoss comes under plants"<<endl;
}

void moss::spaghnales(){
    cout<<"\nSpaghnales is an order of mosses with four living genera"<<endl;
}

void moss::polytrichaceae(){
    cout<<"\nMembers of this family tend to be large than other mosses"<<endl;
}