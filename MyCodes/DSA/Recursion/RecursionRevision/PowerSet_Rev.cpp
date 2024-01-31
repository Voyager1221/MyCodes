// str = "abc"
// "" a ab abc ac b bc c
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void powerSetForString(vector<string>&res, string tempStr, string inputStr, int index, int strLen){
    // Base Condition
    if(index == strLen){
        res.push_back(tempStr);
        return;
    }
    
    powerSetForString(res, tempStr, inputStr, index+1, strLen);

    tempStr = tempStr+inputStr[index];
    powerSetForString(res, tempStr, inputStr, index+1, strLen);
}


int main(){

string inputStr;

cout<<"Enter the string: "<<endl;
cin>>inputStr;

int strLen = inputStr.length();

vector<string>res;

powerSetForString(res, "", inputStr, 0, strLen);

// Sorting vector<string> in descending order
// sort(res.begin(), res.end(), greater<string>());

// Sorting vector<string> in ascending order
sort(res.begin(), res.end(), [](const string& a, const string& b){return a<b;});

cout<<"Printing the Power Set of input string... "<<endl;

for(int i=0; i<res.size(); i++){
    cout<<res[i]<<endl;
}

return 0;

}