#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

void UniqueSubsets(int index, vector<int>&primeFactors, vector<int>&ds, int *cnt){
    (*cnt)++;
    // ans.push_back(ds);
    for(int i=index; i<primeFactors.size(); i++){
        if(i!=index && primeFactors[i]==primeFactors[i-1])continue;
        ds.push_back(primeFactors[i]);
        UniqueSubsets(i+1, primeFactors, ds, cnt);
        ds.pop_back();
    }

}

void FindPrimeFactors(int n, vector<int>&primeFactors)
{
    int cnt=0;
    
    while (n % 2 == 0)
    {
        primeFactors.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if(n>2)primeFactors.push_back(n); 
}
int main(){
    int T;
    cin>>T;

    while(T--){
        int A,B;
        cin>>A>>B;
        vector<int>primeFactors;
        vector<int>ds;
        // vector<vector<int>>ans;
        
        int diff = abs(A-B);
        int cnt=0;
        
        FindPrimeFactors(diff, primeFactors);
        UniqueSubsets(0, primeFactors, ds, &cnt);
        cout<<cnt<<endl;
    }
    return 0;
}