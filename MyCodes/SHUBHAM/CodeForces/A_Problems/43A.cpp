#include <iostream>
#include <map>
using namespace std;

int main(){

    int N;
    cin>>N;
    map <string, int> scoreboard;

    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        scoreboard[s]++;
    }
    int max=INT32_MIN;
    string res;
    for(auto itr: scoreboard){
        if(itr.second>max){
            max = itr.second;
            res = itr.first;
        }
    }
    cout<<res<<endl;
    return 0;
}