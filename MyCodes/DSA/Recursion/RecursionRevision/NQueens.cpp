#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int smallerDifference(int a, int b){
    if(a>b)return b;
    return a;
}

bool nQueens(vector<vector<string>>&visited, vector<vector<int>>&dir, int cnt, int row, int col, int N){
       

    int p = row; int k = col;

    // Marking Top Left Diagonal Visited
    int topLeftRowDiff = row - 0;
    int topLeftColDiff = col - 0;
    int topLeftDiff = smallerDifference(topLeftRowDiff, topLeftColDiff);
    while(topLeftDiff--){
        visited[--p][--k] = ".";
    }

    p = row; k = col;
    // Marking Top Right Diagonal Visited
    int topRightRowDiff = row - 0;
    int topRightColDiff = (N-1) - col;
    int topRightDiff = smallerDifference(topRightRowDiff, topRightColDiff);
    while(topRightDiff--){
        visited[--p][++k] = ".";
    }

    p = row; k = col;
    // Marking Bottom Left Diagonal Visited
    int bottomLeftRowDiff = (N-1) - row;
    int bottomLeftColDiff = col - 0;
    int bottomLeftDiff = smallerDifference(bottomLeftRowDiff, bottomLeftColDiff);
    while(bottomLeftDiff--){
        visited[++p][--k] = ".";
    }

    p = row; k = col;
    // Marking Bottom Right Diagonal Visited
    int bottomRightRowDiff = (N-1) - row;
    int bottomRightColDiff = (N-1) - col;
    int bottomRightDiff = smallerDifference(bottomRightRowDiff, bottomRightColDiff);
    while(bottomRightDiff--){
            visited[++p][++k] = ".";
    }
    
    // Marking Current Row Visited
    for(int colItr=0; colItr<N; colItr++){
        if(colItr != col){
            visited[row][colItr] = ".";
        }
    }
    // Marking Current Column Visited
    for(int rowItr=0; rowItr<N; rowItr++){
        if(rowItr != row){
            visited[rowItr][col] = ".";
        }
    }

    visited[row][col] = "Q";
    cnt++;

    if(cnt == N)return true; 

    for(int itr = 0; itr<8; itr++){
        int di = row + dir[itr][0];
        int dj = col + dir[itr][1];
        if((0<=di && di<N) && (0<=dj && dj<N) && visited[di][dj] == "-1"){

            return nQueens(visited, dir, cnt, di, dj, N);
        }
    }
    return false;
}



void display(vector<vector<string>>&visited){
    cout<<"Printing the results: "<<endl;
    for(int i=0; i<visited.size(); i++){
        for(int j=0; j<visited[i].size(); j++){
            cout<<visited[i][j]<<" ";
            visited[i][j] = "-1";
        }
        cout<<endl;
    }
}


int main(){
    int N;
    cout<<"Enter the side of chessboard: "<<endl;
    cin>>N;

    vector<vector<int>>dir;
    dir = {
            {1,2}, {1,-2}, {-1, 2}, {-1,-2},
            {2,1}, {2,-1}, {-2, 1}, {-2,-1}
          };
    
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            vector<vector<string>>visited(N, vector<string>(N,"-1"));
            bool ans = nQueens(visited, dir, 0, row, col, N);
            if(ans){
                display(visited);
            }            
        }
    }
    return 0;
}