#include <iostream>

using namespace std;


void print1ToN_BackTracking_Rev(int num){
    // Base condition
    if(num == 0){
        return ;
    }
    print1ToN_BackTracking_Rev(num-1);
    cout<<num<<" ";

}


int main(){
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    print1ToN_BackTracking_Rev(num);

    return 0;
}