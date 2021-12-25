#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){

        int n;
        cin>>n;
        vector<ll> vec;
        vector<char> beautiful;
        for(int i=0; i<n; i++){
            ll num;
            cin>>num;
            vec.push_back(num); 
        }

        int flag=-1;
        for(int i=0; i<n; i++){
            ll quo = vec[i];
            for(int j=0; j<n; j++){
                if(vec[j]%quo==0){ 
                    // cout<<"vec[j]: "<<vec[j]<<" quo: "<<quo<<" pb R"<<endl;
                    beautiful.push_back('R');
                }else{
                    beautiful.push_back('B');
                    // cout<<"vec[j]: "<<vec[j]<<" quo: "<<quo<<" pd B"<<endl;
                }
            }

            // for(int j=0; j<n; j++){
            //     cout<<beautiful[j]<<" ";
            // }
            // cout<<endl;

            for(int j=0; j<n-1; j++){
                if(beautiful[j]!=beautiful[j+1]){
                    flag=1;
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cout<<quo<<endl;
                i=n;
                // cout<<"i: "<<n<<endl;
                // exit(0);
            }
            beautiful.clear();
        }
        if(flag==0)cout<<0<<endl;
    }

    return 0;
}