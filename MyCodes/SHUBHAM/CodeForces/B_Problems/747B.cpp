#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    map<char, int> m;
    m['A']=0;
    m['C']=0;
    m['G']=0;
    m['T']=0;
    m['?']=0;

    vector<char> vec;
    vector<char> unequal;
    map<char, bool> equal;
    for(int i=0; i<n; i++){
        char ch;
        cin>>ch;
        m[ch]++;
        vec.push_back(ch);
    }
    
    char arr[] = {'A', 'C', 'G', 'T'};
    int max=-1, min=INT32_MAX, sum=0,index=0;
    char max_ch,min_ch;
    
    for(auto itr: m){
        if(itr.first!='?'){
            if(itr.second==n/4){
                equal[itr.first] = true;
            } else{
                unequal.push_back(itr.first);
                sum += n/4-itr.second;
            }
        }

        if(itr.first!='?' && itr.second>max){
            max = itr.second;
            max_ch = itr.first;
        }
        if(itr.first!='?' && itr.second<min){
            min = itr.second;
            min_ch = itr.first;
        }
    }

    if(n%4!=0 || max>n/4)cout<<"==="<<endl;
    else if(min==max){
        if(m['?']%4==0){
            for(auto itr: vec){
                if(itr!='?')cout<<itr;
                else{
                    if(index>3)index=0;
                    if(m[arr[index]]>=n/4){
                        index +=1;
                    }
                    cout<<arr[index];
                    m[arr[index]]++;
                    // index++;
                }
            }
        }
        else{ 
            cout<<"==="<<endl;
        }
    }else{
        if(m['?']==sum){
            // index=1;
            for(auto itr: vec){
                if(itr!='?'){
                    cout<<itr;
                }
                else{
                    if(index>3)index=0;
                    if(m[unequal[index]]>=n/4){
                        index +=1;
                    }
                    cout<<unequal[index];
                    m[unequal[index]]++;
                    // index++;
                }
            }
        }
        else cout<<"==="<<endl;
    }
    return 0;
}