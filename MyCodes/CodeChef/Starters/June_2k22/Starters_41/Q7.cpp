#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        int arr[N];
        map<int,int> m;

        for(int i=0; i<N; i++){
            cin>>arr[i];
            m[arr[i]]++;
        }

        int mid = N/2;
        int index=0, left=0, right=N-1;
        int cnt=0;
        bool flag = true;
        bool flag2 = true;

        while(left!=right){
            if(left<mid){
                if(m[arr[index]]>1){
                    m[arr[index]]--;
                    cnt++;
                }
                index++;
                left++;
            }else{
                if(flag){
                    index = N-1;
                    flag = false;
                    // cnt = 2*cnt;
                }
                if(m[arr[index]]>1){
                    if(flag2){
                        cnt = 2*cnt;
                    }
                    m[arr[index]]--;
                    cnt++;
                }
                index--;
                right--;
            }
        }
        m.clear();
        for(int i=0; i<N; i++){
            // cin>>arr[i];
            m[arr[i]]++;
        }
        
        int cnt_right=0;
        left=0;
        right = N-1;
        index = N-1;
        flag = true;
        flag2 = true;
        while(left!=right){
            // cout<<"charl raha hai hai"<<endl;
            if(right>mid){
                if(m[arr[index]]>1){
                    m[arr[index]]--;
                    cnt_right++;
                }
                index--;
                right--;
            }else{
                if(flag){
                    index = 0;
                    flag = false;
                    // cnt = 2*cnt;
                }
                if(m[arr[index]]>1){
                    if(flag2){
                        cnt_right = 2*cnt_right;
                        flag2 = false;
                    }
                    m[arr[index]]--;
                    cnt_right++;
                }
                index++;
                left++;
            }
        }
        // cnt--;
        // cout<<"cnt: "<<cnt<<" cnt_right: "<<cnt_right<<endl;
        cout<<min(cnt,cnt_right)<<endl;
    }
    return 0;
}