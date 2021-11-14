#include <iostream>

using namespace std;
//The top class
class livingThings{
    public:
        void print();
        void animals();
        void plants();
        void fungi();
};
void livingThings::print(){
    cout<<"\nHey! This is livingThings' class."<<endl;
}


void livingThings::animals(){
    cout<<"\nAnimals comes under types of living things."<<endl;
}

void livingThings::plants(){
    cout<<"\nPlants comes under types of living things."<<endl;
}

void livingThings::fungi(){
    cout<<"\nFungi comes under types of living things."<<endl;
}

//2nd Generation
class animals: public livingThings{
    public:
        //Can't keep a function name with return type(void included) having name of a class itself
        //void animals();
        
        //We can't directly inherit a function having same name that of a parent class. 
        //We need to declare and define the function having same name that of a parent class.
        void print(); 
        void vertebrates();
        void dinosaurs();
};

void animals::print(){
    cout<<"\nWith love from animals."<<endl;
    cout<<"\nAnimals comes under living things."<<endl;
}

void animals::vertebrates(){
    cout<<"\nWith love from animals."<<endl;
    cout<<"\nVertebrates comes under animal category."<<endl;
}

void animals::dinosaurs(){
    cout<<"\nWith love from animals."<<endl;
    cout<<"\nDinosaurs comes under animal category."<<endl;
}

//2nd Generation
class plants: public livingThings{
    public:
        void print();
        void floweringPlants();
        void moss();
};


void plants::print(){
    cout<<"\nHey! This is plants' class."<<endl;
    cout<<"\nPlants comes under livingThings."<<endl;
}

void plants::floweringPlants(){
    cout<<"\nWith love from plants."<<endl;
    cout<<"\nFlowering Plants are attractive and used for beautification."<<endl;
}

void plants::moss(){
    cout<<"\nWith love from plants."<<endl;
    cout<<"\nMoss are flowerless plants that lacks true roots."<<endl;
}

//2nd Generation
class fungi: public livingThings{
    public:
        void print();
        void sacFungi();
        void eomycota();
};

void fungi::print(){
    cout<<"\nHey! This is fungi's class."<<endl;
}

void fungi::sacFungi(){
    cout<<"\nWith love from fungi."<<endl;
    cout<<"\nThe Ascomycota, formerly knows as the Ascomycetae, are a division of fungi; whose members are known as Sac Fungi."<<endl;
}

void fungi::eomycota(){
    cout<<"\nWith love from fungi."<<endl;
    cout<<"\nA taxonomic sub-kingdom within the kingdom Fungi."<<endl;
}

//3rd Generation => Animals
class vertebrates: public animals{
    public:
        void print();
        void mammals();
        void birds();
};

void vertebrates::print(){
    cout<<"\nHey! This is vertebrates' class."<<endl;
    cout<<"\nVertebrates comes under animals."<<endl;
}

void vertebrates::mammals(){
    cout<<"\nWith Love from mammals."<<endl;
    cout<<"\nMammals are characterized by mammary glands."<<endl;
}

void vertebrates::birds(){
    cout<<"With Love from birds."<<endl;
    cout<<"\n Birds reproduce by laying eggs."<<endl;
}

class dinosaurs: public animals{
    public:
        void print();
        void theropods();
        void sauropods();
}; 

void dinosaurs::print(){
    cout<<"\nHey! This is dinosaurs' class."<<endl;
    cout<<"\nDinosaurs are classified under animals."<<endl;
}

void dinosaurs::theropods(){
    cout<<"\nWith Love from theropods."<<endl;
    cout<<"\nTheropods are characterized by bones and three-toed limbs"<<endl;
}

void dinosaurs::sauropods(){
    cout<<"\nWith love form sauropods."<<endl;
    cout<<"\nSauropods are clade of saurischian."<<endl;
}

//3rd Generation => Plants
class floweringPlants: public plants{
    public:
        void print();
};

void floweringPlants::print(){
    cout<<"\nExamples of flowering plants are lily, daisy, bougainvillea."<<endl;
}
class moss: public plants{
    public:
        void print();
};

void moss::print(){
    cout<<"\nMoss can be seen in forest and also in stagnant water."<<endl;
}

//3rd Generation => Fungi
class sacFungi: public fungi{
    public:
        void print();
};

void sacFungi::print(){
    cout<<"\nSac Fungi includes morels, truffles, brewer's yeast and baker's yeast."<<endl;
}

class eomycota: public fungi{
    public:
        void print();
};

void eomycota::print(){
    cout<<"\nEomycota includes pezizales, cladosporium and halotiales."<<endl;
}

/*
    class livingThing >> class animals
                            > class vertebrates 
                                 > class mammals
                                 > class birds
                            > class dinosaurs 
                                 > class theropods
                                 > class sauropods
                      
                      >> class plants
                            > class floweringPlants
                            > class moss

                      >> class fungi
                            > class sacFungi
                            > class eomycota                 
*/
int main(){
    animals anima;
    anima.print();

    vertebrates verte;
    verte.print();
}