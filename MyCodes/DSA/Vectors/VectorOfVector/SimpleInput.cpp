#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int MX  = 1e5 +5;

//Taking input by reference

void inputVectorOfVector(vector<vector <int>> &vec){
    int u,v;
    cout<<"Enter the co-ords : ";
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);
    //vec.push_back({v,u});

    string ans;
    cout<<"\nDo you want to continue. \nPress y/n or yes/no : ";
    cin>>ans;

    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    if(ans.compare("yes")==0||ans.compare("y")==0){
        inputVectorOfVector(vec);
    }

}

void printVectorOfVector(vector<vector<int>> &vec){
    for(int i=0; i<vec.size(); i++){
        for(auto j : vec[i]){
            cout<<vec[i][0]<<" "<<j<<endl;
        }
    }
}


int main(){

    vector<vector<int>> vec(MX);
    inputVectorOfVector(vec);
    printVectorOfVector(vec);
    return 0;
}