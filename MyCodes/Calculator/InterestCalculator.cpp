#include <iostream>

using namespace std;

class calculator{

    float principle;
    float rate; 
    float time;

    public:
        calculator(float principle=0, float rate=4.5, float time=1){
            this->principle = principle;
            this->rate = rate;
            this->time = time;
        }
        float simpleInterest();
        float compoundInterest();
        void display();
};

float calculator::simpleInterest(){
    return (this->principle*this->rate*this->time)/100;
}

float calculator::compoundInterest(){
    while((this->time)-->0){
        this->principle = this->principle + (this->principle*this->rate)/100;
    }
    return this->principle; 
}

void calculator::display(){
    cout<<fixed<<"\nThe principle is : "<<this->principle<<endl;
}

int main(){

    calculator aayush(16000000, 5, 20);
    aayush.compoundInterest();
    aayush.display();

}