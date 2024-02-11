#include <iostream>
#include <vector>

using namespace std;

int smallerDifference(int a, int b){
    if(a>b)return b;
    return a;
}

void nQueens(vector<vector<string>>&visited, vector<vector<int>>&dir, vector<string>&temp, int row, int col, int N){
    int p = row; int k = col;
    visited[row][col] = 'Q';

    // Marking Top Left Diagonal Visited
    int topLeftRowDiff = row - 0;
    int topLeftColDiff = col - 0;
    int topLeftDiff = smallerDifference(topLeftRowDiff, topLeftColDiff);
    while(topLeftDiff--){
        visited[--p][--k] = '.';
    }

    p = row; k = col;
    // Marking Top Right Diagonal Visited
    int topRightRowDiff = row - 0;
    int topRightColDiff = N - col;
    int topRightDiff = smallerDifference(topRightRowDiff, topRightColDiff);
    while(topRightDiff--){
        visited[--p][++k] = '.';
    }

    p = row; k = col;
    // Marking Bottom Left Diagonal Visited
    int bottomLeftRowDiff = N - row;
    int bottomLeftColDiff = col - 0;
    int bottomLeftDiff = smallerDifference(bottomLeftRowDiff, bottomLeftColDiff);
    while(bottomLeftDiff--){
        visited[++p][--k] = '.';
    }

    p = row; k = col;
    // Marking Bottom Right Diagonal Visited
    int bottomRightRowDiff = N - row;
    int bottomRightColDiff = N - col;
    int bottomRightDiff = smallerDifference(bottomRightRowDiff, bottomRightColDiff);
    while(bottomRightDiff--){
            visited[++p][++k] = '.';
    }

    // Marking Current Row Visited
    for(int colItr=0; colItr<N; colItr++){
        visited[row][colItr] = '.';
    }
    // Marking Current Column Visited
    for(int rowItr=0; rowItr<N; rowItr++){
        visited[rowItr][col] = '.';
    }

    for(int itr = 0; itr<8; itr++){
        int di = row + dir[itr][0];
        int dj = col + dir[itr][1];
        if((0<=di && di<N) && (0<=dj && dj<N) && visited[di][dj] == "0"){
            nQueens(visited, dir, temp, di, dj, N);
        }
    }
}


int main(){
    int N;
    cout<<"Enter the side of chessboard: "<<endl;
    cin>>N;

    vector<string>temp(N, ".");
    vector<bool>rowsVis(N, false);
    vector<bool>colsVis(N, false);
    vector<vector<int>>dir;
    dir = {
            {1,2}, {1,-2}, {-1, 2}, {-1,-2},
            {2,1}, {2,-1}, {-2, 1}, {-2,-1}
          };
    vector<vector<string>>visited(N, vector<string>(N,"0"));
    nQueens(visited, dir, temp, 0, 0, N);


    return 0;
}