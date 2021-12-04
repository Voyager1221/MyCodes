#include <iostream>

using namespace std;

struct coOrd{
    int x;
    int y;
};

bool check_Border(int xK, int yK){
    if(xK==1 || xK==8 || yK==1 || yK==8){
        return true;
    }
    return false;
}

bool check_corner(coOrd K, coOrd R1, coOrd R2){
    if(K.x-K.y==0 || K.y-K.x==0 || K.x-K.y==7 || K.y-K.x==7){
        if((K.x-R1.x==1 && K.x-R2.x==1) ||(R1.x-K.x==1 && R2.x-K.x==1)){
            if((K.y+2<R1.y && K.y+2<R2.y) || (K.y-2>R1.y && K.y-2>R2.y)){
                return true;
            }
        }
        if((K.y-R1.y==1 && K.y-R2.y==1) ||(R1.y-K.y==1 && R2.y-K.y==1)){
            if((K.x+2<R1.x && K.x+2<R2.x) || (K.x-2>R1.x && K.x-2>R2.x)){
                return true;
            }
        }

    }
    return false; 
}


bool good_Position(coOrd K, coOrd R1, coOrd R2){
    if((R1.y-K.y==1 && R2.y-K.y==1) || (K.y-R1.y==1 && K.y-R2.y==1)){
        // if((R1.x-K.x==1 && R2.x-K.x==-1) || (R1.x-K.x==-1 && R2.x-K.x==1)){
        //     return false;
        // }
        if(R1.x-R2.x>3 || R2.x-R1.x>3){
            return true;
        }
        if(R1.x-R2.x==1 || R2.x-R1.x==1){
            if(R1.x-K.x>=1 || K.x-R1.x>=1 || R2.x-K.x>=1 || K.x-R2.x>=1){
                return true;
            }
        }
        return false;
    }
    if((R1.x-K.x==1 && R2.x-K.x==1) || (K.x-R1.x==1 && K.x-R2.x==1)){
        // if((R1.y-K.y==1 && R2.y-K.y==-1) || (R1.y-K.y==-1 && R2.y-K.y==1)){
        //     return false;
        // }
        if(R1.y-R2.y>3 || R2.y-R1.y>3){
            return true;
        }
        else if(R1.y-R2.y==1 || R2.y-R1.y==1){
            if(R1.y-K.y>=1 || K.y-R1.y>=1 || R2.y-K.y>=1 || K.y-R2.y>=1){
                return true;
            }
        }
        return false;
    }
    if((R1.x>K.x+2 || R1.x<K.x-2) && (R2.x>K.x+2 || R2.x<K.x-2)){
        if(R1.y-K.y==1 || K.y-R1.y==1 || K.y-R2.y==1 || R2.y-K.y==1){
            if(R1.x!=R2.x && R1.y!=R2.y){
                // cout<<"Good_Position 1st if's nested if."<<endl;
                return true;
            }
        }
    }
    if((R1.y>K.y+2 || R1.y<K.y-2) && (R2.y>K.y+2 || R2.y<K.y-2)){
        if(R1.x-K.x==1 || K.x-R1.x==1 || K.x-R2.x==1 || R2.x-K.x==1){
            if(R1.x!=R2.x && R1.y!=R2.y){
                // cout<<"Good_Position 2nd if's nested if."<<endl;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int xK, yK, x1, y1, x2, y2;
    cin>>xK>>yK;
    cin>>x1>>y1;
    cin>>x2>>y2;

    if(check_Border(xK, yK)){
        // cout<<"\nCheck Border Good"<<endl;
        coOrd K, R1, R2;
        bool res;
        int flag=1;
        K.x = xK;   K.y = yK;    
        R1.x = x1;  R1.y = y1;
        R2.x = x2;  R2.y = y2;
        
        res = check_corner(K, R1, R2);
        if(res){
            flag=0;
            cout<<"Yes"<<endl;
        }
        if(flag==1){
            res = good_Position(K, R1, R2);
            // cout<<"Returned value of good_Position: "<<res<<endl;
            if(res){
                // cout<<"\nGood_Postion is true."<<endl;
                cout<<"Yes"<<endl;
            }else {
                // cout<<"\nGood_Position is false"<<endl;
                cout<<"No"<<endl;
            }
        }
    }else {
        // cout<<"\nExecuted last else as No."<<endl;
        cout<<"No"<<endl;}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}