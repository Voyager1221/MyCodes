#include <iostream>
#include <stack>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int L;
        cin>>L;
        string S;
        cin>>S;

        stack<char>st;
        bool flag=true;
        for(int i=0; i<L; i++){
            if(S[i]=='H'){
                if(st.empty())st.push(S[i]);
                else{
                    flag = false;
                    break;
                }
            }else if (S[i]=='T'){
                if(!st.empty())st.pop();
                else{
                    flag=false;
                    break;
                }
            }else continue;
        } 
        if(st.empty() && flag)cout<<"Valid"<<endl;
        else cout<<"Invalid"<<endl;
    }
    return 0;
}