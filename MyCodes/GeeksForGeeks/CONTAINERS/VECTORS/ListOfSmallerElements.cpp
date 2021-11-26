#include <iostream>
#include <vector>

using namespace std;

vector<int> SmallerElements(vector<int> &v_ref, int k){
    vector<int> list;
    for(auto &i: v_ref){
        if(i<=k){
            list.push_back(i);
        }
    }
    return list;
}

int main(){

    int n, k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    // auto itr = SmallerElements(vec, k);
    // itr.erase(itr.begin(), itr.begin()+n);
    // for(auto &i: itr){
    //     cout<<i<<" ";
    // }

    //OR
    
    vector<int>li = SmallerElements(vec, k);
    li.erase(li.begin(), li.begin()+n);
    for(auto &i: li){
        cout<<i<<" ";
    }
    
    return 0;
}