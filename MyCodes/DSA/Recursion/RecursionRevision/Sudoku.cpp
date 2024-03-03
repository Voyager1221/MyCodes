#include<iostream>
#include<vector>
#include<string>

using namespace std;


void hashingNumOccurence(vector<vector<char>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int p, int q, int x, int r, int num, int N){
// void hashingNumOccurence(vector<vector<string>>&sudokuMatrix, int p, int q, int num){
    sudokuMatrix[p][q] = '0' +(num);
    rowHashMap[p][num] = 1;
    colHashMap[q][num] = 1;
    subMatrixHashMap[r][num] = 1;

    // sudokuMatrix[p][q] = to_string(num);

}

void unHashingNumOccurence(vector<vector<char>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int p, int q, int x, int r, int num, int N){
// void unHashingNumOccurence(vector<vector<string>>&sudokuMatrix, int p, int q, int num){
    sudokuMatrix[p][q] = '.';
    rowHashMap[p][num] = 0;
    colHashMap[q][num] = 0;
    subMatrixHashMap[r][num] = 0;

    // sudokuMatrix[p][q] = ".";

}

void display(vector<vector<int>>&vec){
    for(auto i:vec){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void displayRes(vector<vector<char>>&vec){
    cout<<"Printing the result..."<<endl;
    for(auto i:vec){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void sudokuSolver_best(vector<vector<char>>&sudokuMatrix, int x, int y, int N){
    // Base Condition
    
    
}

void sudokuSolver_better(vector<vector<char>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int x, int y, int cnt, int N){
    // Base Condition
    if(x==9 || y== 81){
        displayRes(sudokuMatrix);
        return;
    }

    int itr = y%9;

    int p = 3*(x/3)+ (itr/3);
    int q = 3*(x%3) + (itr%3);

    if(sudokuMatrix[p][q]=='.'){
        int r = 2*(p/3) + (p/3) +(q/3);

        for(int num=1; num<=9; num++){

            if(rowHashMap[p][num]==0 && colHashMap[q][num]==0){
            // if(sudokuMatrix[p][num-1]=="." && sudokuMatrix[num-1][q]=="."){
                       
                if(subMatrixHashMap[r][num]==0){        
                // if(sudokuMatrix[r][num-1]=="."){        
                    // hashingNumOccurence(sudokuMatrix, p, q, num);
                    hashingNumOccurence(sudokuMatrix,rowHashMap, colHashMap, subMatrixHashMap, p, q, y/9, r, num, N);
                    // displayRes(sudokuMatrix);
                    sudokuSolver_better(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, (y+1)/9, y+1, cnt+1, N);
                    // unHashingNumOccurence(sudokuMatrix, p, q, num);                    
                    unHashingNumOccurence(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, p, q, y/9, r, num, N);                    
                }
            }
        }
        return;

    }
    sudokuSolver_better(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, (y+1)/9, y+1, cnt+1, N);

}

int main(){

    vector<vector<int>>rowHashMap(9, vector<int>(10, 0));
    vector<vector<int>>colHashMap(9, vector<int>(10, 0));
    vector<vector<int>>subMatrixHashMap(9, vector<int>(10,0));
    // vector<vector<string>>sudokuMatrix(9, vector<string>(9, ""));

    vector<vector<char>>sudokuMatrix;
    sudokuMatrix = {    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
                    };
    int N = 9;
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            char c = sudokuMatrix[row][col];
            
            if(c!='.'){
                int num = (c) - '0';
                rowHashMap[row][num] = 1;
                colHashMap[col][num] = 1;

                int p = row/3;
                int q = col/3;
                // r represents the o based indexing of sub-matrices ranging 0-8, wiz [0-1-2][3-4-5][6-7-8]. Each index is a sub-matrix in itself.
                int r = (row/3)*2 + p+q;
                // int r = row + q; but this will not give us the required ans, because we are storing value in int data type hence missing the fractional values.

                subMatrixHashMap[r][num] = 1;
            }
        }
    }
    cout<<"Printing the matrix of rolHashMap"<<endl;
    display(rowHashMap);
    cout<<"Printing the matrix of colHashMap"<<endl;
    display(colHashMap);
    cout<<"Printing the matrix of subMatrixHashMap"<<endl;
    display(subMatrixHashMap);

    // sudokuSolver(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, 0, 0, 0, N);
    sudokuSolver_better(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, 0, 0, 0, N);

    return 0;
}