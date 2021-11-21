#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MX = 1e5 +5;

void input(vector<pair<string, int>> &vec){
    string s;
    
    cout<<"\nEnter the string : ";
    cin>>s;

    vec.push_back({s, 1});

    string ans;
    cout<<"\nDo you want to continue. \nPress y/n or yes/no : ";
    cin>>ans;

    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    if(ans.compare("yes")==0||ans.compare("y")==0){
        input(vec);
    }
}

void print(vector<pair<string, int>> &vec){
    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }
}

int main(){

    vector<pair<string, int>> vop(MX);

    input(vop);
    print(vop);
    return 0;
}
