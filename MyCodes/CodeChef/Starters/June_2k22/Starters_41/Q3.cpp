#include<iostream>
#include <math.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int Pa, Pb, Qa, Qb;
        cin>>Pa>>Pb>>Qa>>Qb;

        int Pen_P = max(Pa, Pb);
        int Pen_Q = max(Qa, Qb);

        if(Pen_P<Pen_Q)cout<<"P"<<endl;
        else if(Pen_P>Pen_Q)cout<<"Q"<<endl;
        else cout<<"TIE"<<endl;
    }
    return 0;
}