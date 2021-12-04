#include <iostream>

using namespace std;

void solve(){
    int H,V;
    cin>>H>>V;
    int max=0;
    char ch;
    if(H==V){
        max = H;
        ch = 'E';
    }
    else if(H>V){
        max = H;
        ch = 'H';
    }else{
        max = V;
        ch = 'V';
    }

    if(ch=='H'){
        cout<<2*max+1<<endl;
        for(int i=0; i<=2*max; i++){
            if(i%2==0) cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }else if(ch=='V'){
        cout<<2*max+1<<endl;        
        for(int i=0; i<=2*max; i++){
            if(i%2==0) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }else{
        cout<<2*max+2<<endl;        
        for(int i=0; i<=2*max+1; i++){
            if(i%2==0) cout<<0;
            else cout<<1;    
        }
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