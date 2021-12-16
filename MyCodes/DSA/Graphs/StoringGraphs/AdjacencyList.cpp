#include <iostream>
#include <vector>

using namespace std;

int main(){

    int nodes, edges;
    cin>>nodes>>edges;
    vector<vector<int>> vec(nodes+1);
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cout<<"\nPrinting the elements"<<endl;

    for(int i=1; i<=nodes; i++){
        for(auto j : vec[i]){

            cout<<vec[i][0]<<" "<<j<<endl;
        }
    }

    cout<<"\nPrinting via both the for loops as auto."<<endl;
    for(auto i: vec){
        for(auto j : i){
         
            cout<<j<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nPrinting  j as int  form."<<endl;
    for(auto i: vec){
        for(int j : i){
            cout<<j<<" ";
        }
           cout<<endl;
    }
    
    cout<<"\nPrinting i as int form."<<endl;
    for(auto &i: vec){
        for(auto &j : i){
         
            cout<<*(--i.begin())<<" "<<j<<endl;
        }
        //cout<<"\n";
    }

    cout<<"\nPrinting the correct pair in adjacency list"<<endl;
    
    for(int i=0; i<nodes+1; i++){
        for(int j : vec[i]){
            cout<<i<<" "<<j<<endl;
        }
    }

    return 0;
}
/*
    1-> 1,2,3
    
*/