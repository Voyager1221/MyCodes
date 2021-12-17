#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> vec;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end(), greater<int>());
    cout<<vec[k-1]<<endl;
}