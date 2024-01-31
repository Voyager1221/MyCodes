#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int minCost(vector<int>money){
    sort(money.begin(), money.end(), greater<int>());
    int upperLimit = money[0]-1;
    int lowerLimit = (money[0]+1)/2;
    map<int,int>m;
    for(auto itr: money){
        m[itr]++;
    }
    for(auto itr:m)if(itr.second==money.size()){return 0;}
    int ans = m[money[0]];

    for(int i=0; i<money.size(); i++){
        if(upperLimit>=money[i] && lowerLimit<=money[i]){
            continue;
        }else{
            while(money[i]<lowerLimit){
                money[i]*=2;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int>money(N);
        for(int i=0; i<N; i++){
            cin>>money[i];
        }
        cout<<minCost(money)<<endl;
    }
}