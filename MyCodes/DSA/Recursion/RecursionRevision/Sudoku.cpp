#include<iostream>
#include<vector>
#include<string>

using namespace std;

void sudokuSolver(vector<vector<string>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, int row, int col){

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

    return 0;
}