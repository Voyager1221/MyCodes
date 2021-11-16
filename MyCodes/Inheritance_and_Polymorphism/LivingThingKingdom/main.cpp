#include<iostream>
#include "livingThings.cpp"
#include "animals.cpp"
#include "plants.cpp"
#include "fungi.cpp"

using namespace std;

int main(){
    animals anima;
    anima.print();
    anima.dinosaurs();
    anima.vertebrates();

    plants pla;
    pla.print();
    pla.floweringPlants();
    pla.moss();

    fungi fung;
    fung.print();
    fung.sacFungi();
    fung.eomycota();

    return 0;
}