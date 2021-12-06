#include <iostream>
#include <cmath>
using namespace std;

struct CoOrds{
    int x;
    int y;
};

bool check_Border(CoOrds K){
    if(K.x==1 || K.x==8 || K.y==1 || K.y==8){
        return true;
    }
    return false;    
}

bool good_Position(CoOrds K, CoOrds R1, CoOrds R2){
    if(abs(R1.x-K.x)>=2 && abs(R2.x - K.x)>=2){
        if(abs(R1.y-K.y)==1 || abs(R2.y-K.y)==1){
            if(R1.x!=R2.x){
                return true;
            }
        }
    }
    else if(abs(R1.y-K.y)>=2 && abs(R2.y - K.y)>=2){
        if(abs(R1.x-K.x)==1 || abs(R2.x-K.x)==1){
            if(R1.y!=R2.y){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    CoOrds K, R1, R2;
    cin>>K.x>>K.y;
    cin>>R1.x>>R1.y;
    cin>>R2.x>>R2.y;

    bool res;
    if(check_Border(K)){
        if(good_Position(K, R1, R2)){
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }else{ 
        cout<<"No"<<endl;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}