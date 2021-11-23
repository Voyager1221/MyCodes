#include <iostream>
#include <algorithm>
using namespace std;

void countVotes(){
    int x,y,z;
    cin>>x>>y>>z;

    if(x>y && x>z)cout<<"0 ";
    else cout<<max(y,z) -x +1<<" ";

    if(y>x && y>z)cout<<"0 ";
    else cout<<max(x,z) -y +1<<" ";

    if(z>x && z>y)cout<<"0 "<<endl;
    else cout<<max(x,y) -z +1<<endl;

    cout<<"\n"<<endl;

}

int main(){

    int T;
    cin>>T;
    while(T--){
        countVotes();
    }
    return 0;
}