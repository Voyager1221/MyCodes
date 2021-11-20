//Taking input for vector via reference and value
// as well. And printing the input values 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
void inputVector(vector<T> &vec){
    T value;
    cout<<"Enter the value : ";
    cin>>value;

    vec.push_back(value);
    string ans;
    cout<<"\nDo you want to continue. \nPress y/n or yes/no : ";
    cin>>ans;

    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    if(ans.compare("yes")==0||ans.compare("y")==0){
        inputVector(vec);
    }
}

template <class T>
vector<T> vec_by_value;

template <class T>
void inputVectorByValue(vector<T> &temp){
    
    T value;
    cout<<"\nEnter the value in vector : ";
    cin>>value;

    vec_by_value<T>.push_back(value);

    string ans;
    cout<<"\nDo you want to continue. Press y/n or yes/no : ";
    cin>>ans;
    if(ans.compare("yes")==0 || ans.compare("y")==0){
        inputVectorByValue(temp);
    }
}

template <class T>
void printVector(vector<T> &vec){
    cout<<endl;
    for(auto itr: vec){
        cout<<itr<<" "<<endl;
    }
}


int main(){
    //vector<int> vec;
    //vector<float> vec;
    vector<string> vec;

    inputVector(vec);
    printVector(vec);

    // inputVectorByValue(vec_by_value<int>);
    // printVector(vec_by_value<int>);
    
    inputVectorByValue(vec_by_value<string>);
    printVector(vec_by_value<string>);
    return 0;
}
