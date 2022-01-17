#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        ll n,k, sum=0, min=INT_MAX, max=INT_MIN;
        cin>>n>>k;

        vector<int> vec();

        for(int i=0; i<n; i++){
            ll num;
            cin>>num;
            vec.push_back(num);
            if(num<min)min=num;
            if(num>max)max=num;
            sum += num;
        }
        bool flag=true;
        ll cnt=0;
        while(flag){
            if(min==max){
                if(sum>k){
                    cnt = cnt+(n*min)-k;
                }
                cout<<cnt<<endl;
                flag = false;
            }else{
                sort(vec.begin(), vec.end());
                // vector<ll,ll>::reverse_iterator itr;
                for(auto itr=vec.rbegin(); itr!=vec.rend(); itr++){
                    if((*itr)!=min){
                        sum = sum - (*itr) + min;
                        cnt++;
                        if(sum<=k){
                            cout<<cnt<<endl;
                            itr = vec.rend();
                            flag = false;
                        }
                    }else{
                        max = min;
                        itr = vec.rend();
                    }
                }
            }
        }
    }
    return 0;
}
