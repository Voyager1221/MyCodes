#include <iostream>
#include <vector>
const int MX = 1e5 + 5;
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<int> vec(MX);
    for(int i=1; i<=m; i++){
        int num;
        cin>>num;
        vec[num] += 1;
    }
    int min=1e9 +5;
    for(int i=1; i<=n; i++){
        // cout<<vec[i]<<" ";
        if(min>vec[i]){
            min = vec[i];
        }
    }
    cout<<min<<endl;
    return 0;
}