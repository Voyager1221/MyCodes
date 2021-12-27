#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int max=INT32_MIN, index;
    // vector<int> line;
    // vector<int> completed;
    for(int i=1; i<=n; i++){
        int num;
        cin>>num;
        if((num+m-1)/m>=max){
            index = i;
            max = (num+m-1)/m;
        }
        // line.push_back(num);
    }
    cout<<index<<endl;
    return 0;
}