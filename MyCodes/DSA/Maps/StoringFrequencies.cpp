#include <map>
#include <iostream>
#include <iterator>

using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    map <int , int> m;
    map <int , int> :: iterator it;
    for(int i=1; i<=n; i++){
        int a;
        cin>>a; 
        m[a]++;
    }

    cout<<"\nPrinting with traditional method"<<endl;

    for(it = m.begin(); it!=m.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;       
    }

    cout<<"\nPrinting with lambda function"<<endl;

    for(auto itr1 : m){
        cout<<(&itr1)->first<<" "<<itr1.second<<endl;
    }
    
    cout<<"\nPrinting with lambda function by passing by reference"<<endl;
    for(auto &itr2: m){
        cout<<itr2.first<<" "<<(&itr2)->second<<endl;
    }

    return 0;
}