#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
vector<int> hasVowels(vector<string> strArr, vector<string> query){
    int numStr = strArr.size();
    int numQueries = query.size();

    vector<vector<int>>actQuery(numQueries, vector<int>(2, 0));
    vector<int>results;
    for(int i=0; i<numQueries; i++){
        string str = query[i];
        int len = str.length();
        for(int j=0; j<len; j++){
            if(str[j]=='-'){
                // cout<<"Printing the value of Left: "<<str.substr(0,j)<<endl;
                // cout<<"Printing the value of Right: "<<str.substr(j+1, len-j-1)<<endl;
                actQuery[i][0] = stoi(str.substr(0,j));
                actQuery[i][1] = stoi(str.substr(j+1, len-j-1));
                // cout<<"actQuery[i][0]: "<< actQuery[i][0]<<endl;
                // cout<<"actQuery[i][1]: "<< actQuery[i][1]<<endl;

                break;
            }
        }
    }
    for(int i=0; i<numStr; i++){
        
        string str = strArr[i];
        int len = str.length();
        
        vector<int> pre(len, 0);
        
        if(isVowel(str[0]))pre[0] = 1;
        else pre[0] = 0;

        for(int j=0; j<str.length(); j++){
            if(isVowel(str[i])){
                pre[i] = 1+pre[i-1];
            }else{
                pre[i] = pre[i-1];
            }
        }

        for(int j=0; j<numQueries; j++){
            if(query[i][0]==0){
                results.push_back(pre[query[i][1]]);    
            }else{
                results.push_back(pre[query[i][1]]-pre[query[i][0]-1]);
            }
        }
    }
    return results;
}

int main(){
    int N,M;
    cin>>N;

    vector<string> strArr(N, "");
    
    for(int i=0; i<N; i++){
        cin>>strArr[i];
    }

    cin>>M;
    vector<string> query(M, "");
    for(int i=0; i<M; i++){
        cin>>query[i];
    }
    vector<int>results;

    results = hasVowels(strArr, query);
    cout<<"The length of results vector is : "<<results.size()<<endl;
    for(auto itr: results){
        cout<<itr<<" ";
    }
    cout<<endl;
}