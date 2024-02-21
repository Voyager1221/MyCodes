#include<iostream>
#include<vector>
#include<string>

using namespace std;

void sudokuSolver(vector<vector<string>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, int x, int y, int N){
    
    // int row = 3*(x/3)+ (y/3);
    // int col = 3*(x%3) + (y%3);

    for(int )
}

int main(){

    vector<vector<int>>rowHashMap(9, vector<int>(10, 0));
    vector<vector<int>>colHashMap(9, vector<int>(10, 0));
    vector<vector<string>>sudokuMatrix(9, vector<string>(9, ""));

    int N = 9;
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            string s;
            cin>>s;
            sudokuMatrix[row][col] = s;
            if(s!="."){
                rowHashMap[row][stoi(s)] = 1;
                colHashMap[col][stoi(s)] = 1;
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     int cnt = 0;
    //     for(int j=0; j<N; j++){
    //         int x = 3*(i/3)+ (j/3);
    //         int y = 3*(i%3) + (j%3);
    //         cout<<"( "<<x<<", "<<y<<" ) ";
    //         cnt++;
    //         if(cnt%3==0)cout<<endl;
    //     }
    //     cout<<"\n"<<endl;
    // }
    return 0;
}