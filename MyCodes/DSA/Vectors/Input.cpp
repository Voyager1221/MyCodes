#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
void inputVector(vector<T> &vec){
    int value;
    cout<<"Enter the value : ";
    cin>>value;

    vec.push_back(value);
    string ans;
    cout<<"Do you want to continue. \nPress y/n or yes/no : ";
    cin>>ans;

    std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    if(ans.compare("yes")==0||ans.compare("y")==0){
        inputVector(vec);
    }
}

template <class T>
void printVector(vector<T> &vec){
    for(auto itr: vec){
        cout<<itr<<" "<<endl;
    }
}


int main(){
    vector<int> vec;
    inputVector(vec);
    printVector(vec);
    return 0;
}
