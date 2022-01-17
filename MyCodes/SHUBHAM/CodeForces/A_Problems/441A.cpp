#include <iostream>
#include <set>

using namespace std;

int main(){
    int n,v;
    cin>>n>>v;
    set<int> s;
    for(int i=1; i<=n; i++){
        int m;
        cin>>m;
        for(int y=1; y<=m; y++){
            int cost;
            cin>>cost;
            if(v>cost){
                s.insert(i);
                // break;
            }
        }
    }
    if(s.size()!=0){
        cout<<s.size()<<endl;
        set<int>::iterator itr;
        for(itr=s.begin(); itr!=s.end(); itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }else cout<<0<<endl;
    return 0;
}