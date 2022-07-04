#include <iostream>
#include <vector>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>&points){
    
    vector<int>prev(4);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);

    prev[3] = max(max(prev[0], prev[1]), prev[2]);
    
    for(int day=1; day<n; day++){
        vector<int>temp(4,0);
        for(int lastTask=0; lastTask<4; lastTask++){
            for(int task=0; task<3; task++){
                if(task!=lastTask){
                    temp[lastTask] = max(temp[lastTask], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }   
    return prev[3];
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>>points(n, vector<int>(3,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++)cin>>points[i][j];
        }
        cout<< ninjaTraining(n, points)<<endl;
    }
    return 0;
}