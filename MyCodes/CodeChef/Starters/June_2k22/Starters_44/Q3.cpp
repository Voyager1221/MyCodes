#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X1,X2,Y1,Y2;
        cin>>X1>>Y1>>X2>>Y2;
        // int deltaX = abs(X2-X1);
        // int deltaY = abs(Y2-Y1);
        // if((deltaX==1 || deltaX==3) && deltaX==deltaY)cout<<"Yes"<<endl;
        // else if(Y1==Y2 && (deltaX==2 || deltaX==4))cout<<"Yes"<<endl;
        // else if(X1==X2 && (deltaY==2 || deltaY==4))cout<<"Yes"<<endl;
        // else if(deltaY==2 && deltaX==4)cout<<"Yes"<<endl;
        // else if(deltaX==2 && deltaY==4)cout<<"Yes"<<endl;
        // else if(deltaY==3 && deltaX==1)cout<<"Yes"<<endl;
        // else if(deltaX==3 && deltaY==1)cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;    
    vector<pair<int,int>>dir = {{1,2}, {1,-2}, {-1, 2}, {-1,-2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector<pair<int,int>>coOrds1;
        vector<pair<int,int>>coOrds2;
        for(auto itr:dir){
            int dx = itr.first;
            int dy = itr.second;
            if(dx+X1<=8 && X1+dx>0 && dy+Y1<=8 && dy+Y1>0){
                coOrds1.push_back({X1+dx, Y1+dy});
            }
            if(dx+X2<=8 && X2+dx>0 && dy+Y2<=8 && dy+Y2>0){
                coOrds2.push_back({X2+dx, Y2+dy});
            }
        }
        bool flag = true;
        for(int i=0; i<coOrds1.size(); i++){
            for(int j=0; j<coOrds2.size(); j++){
                if(coOrds1[i].first==coOrds2[j].first && coOrds1[i].second==coOrds2[j].second){
                    flag = false;
                    cout<<"Yes"<<endl;
                    i = coOrds1.size();
                    break;
                }
            }
        }
        if(!flag)cout<<"No"<<endl;
    }
    return 0;
}