#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> m;
    m[0] = "abdce";
    m.insert(make_pair(18, "aoraihv"));
    m.insert({12, "aivhs"});
    m[14] = "abhirbdfg";

    auto it = m.find(18);
    for(auto &it : m){
        cout<<it.first<<" ";
    }
    cout<<endl;
    if(it==m.end()){
        cout<<"No Value Exists"<<endl;
    }else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
        //cout<<(*it);
    }
    cout<<m[m.size()-1]<<endl;
    return 0;
}