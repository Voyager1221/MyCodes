#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int smallerDifference(int a, int b){
    if(a>b)return b;
    return a;
}

void spDisplay(vector<vector<string>>&visited){
    // cout<<"Printing the results: "<<endl;
    for(int i=0; i<visited.size(); i++){
        for(int j=0; j<visited[i].size(); j++){
            cout<<visited[i][j]<<" ";
            // visited[i][j] = "-1";
        }
        cout<<endl;
    }
}


void display(vector<vector<string>>&ans){
    cout<<"Printing the results: "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Incorrect Solution
// bool nQueens(vector<vector<string>>visited, int cnt, int row, int col, int N){
       

//     int p = row; int k = col;

//     // Marking Top Left Diagonal Visited
//     int topLeftRowDiff = row - 0;
//     int topLeftColDiff = col - 0;
//     int topLeftDiff = smallerDifference(topLeftRowDiff, topLeftColDiff);
//     while(topLeftDiff--){
//         visited[--p][--k] = ".";
//     }

//     p = row; k = col;
//     // Marking Top Right Diagonal Visited
//     int topRightRowDiff = row - 0;
//     int topRightColDiff = (N-1) - col;
//     int topRightDiff = smallerDifference(topRightRowDiff, topRightColDiff);
//     while(topRightDiff--){
//         visited[--p][++k] = ".";
//     }

//     p = row; k = col;
//     // Marking Bottom Left Diagonal Visited
//     int bottomLeftRowDiff = (N-1) - row;
//     int bottomLeftColDiff = col - 0;
//     int bottomLeftDiff = smallerDifference(bottomLeftRowDiff, bottomLeftColDiff);
//     while(bottomLeftDiff--){
//         visited[++p][--k] = ".";
//     }

//     p = row; k = col;
//     // Marking Bottom Right Diagonal Visited
//     int bottomRightRowDiff = (N-1) - row;
//     int bottomRightColDiff = (N-1) - col;
//     int bottomRightDiff = smallerDifference(bottomRightRowDiff, bottomRightColDiff);
//     while(bottomRightDiff--){
//             visited[++p][++k] = ".";
//     }
    
//     // Marking Current Row Visited
//     for(int colItr=0; colItr<N; colItr++){
//         if(colItr != col){
//             visited[row][colItr] = ".";
//         }
//     }
//     // Marking Current Column Visited
//     for(int rowItr=0; rowItr<N; rowItr++){
//         if(rowItr != row){
//             visited[rowItr][col] = ".";
//         }
//     }

//     visited[row][col] = "Q";
//     cnt++;

//     if(cnt == N){
//         display(visited);
//         return true;
//     }; 
//     // This logic limits the Placement of Queens to just +-2 postions around last queen. Imagine in the case of matrix size greater than 5, there are many cells which will get miss by this method.
//     // for(int itr = 0; itr<8; itr++){
//     //     int di = row + dir[itr][0];
//     //     int dj = col + dir[itr][1];
//     //     if((0<=di && di<N) && (0<=dj && dj<N) && visited[di][dj] == "-1"){
//     //         cout<<"Printing while recursing..."<<endl;
//     //         spDisplay(visited);
//     //         if(nQueens(visited, dir, cnt, di, dj, N))return true;
//     //     }
//     // }
//     for(int colItr = 0; colItr<N; colItr++){
//         if((row+1<=N) && (visited[row+1][colItr]=="-1")){
//             if(nQueens(visited, cnt, row+1, colItr, N))return true;
//             // visited[row+1][colItr] = "-1";
//         }
//     }
//     return false;
// }

// Try to save Space used by graph in here.
// Method-I: We need to unmark all the location in the end of function
// Method-II: We don't pass the graph as reference which means no optimization
// Method-III: Change the method.

// bool nQueens(vector<vector<string>>visited, int cnt, int row, int col, int N){
       

//     int p = row; int k = col;

//     // Marking Top Left Diagonal Visited
//     int topLeftRowDiff = row - 0;
//     int topLeftColDiff = col - 0;
//     int topLeftDiff = smallerDifference(topLeftRowDiff, topLeftColDiff);
//     while(topLeftDiff--){
//         visited[--p][--k] = ".";
//     }

//     p = row; k = col;
//     // Marking Top Right Diagonal Visited
//     int topRightRowDiff = row - 0;
//     int topRightColDiff = (N-1) - col;
//     int topRightDiff = smallerDifference(topRightRowDiff, topRightColDiff);
//     while(topRightDiff--){
//         visited[--p][++k] = ".";
//     }

//     p = row; k = col;
//     // Marking Bottom Left Diagonal Visited
//     int bottomLeftRowDiff = (N-1) - row;
//     int bottomLeftColDiff = col - 0;
//     int bottomLeftDiff = smallerDifference(bottomLeftRowDiff, bottomLeftColDiff);
//     while(bottomLeftDiff--){
//         visited[++p][--k] = ".";
//     }

//     p = row; k = col;
//     // Marking Bottom Right Diagonal Visited
//     int bottomRightRowDiff = (N-1) - row;
//     int bottomRightColDiff = (N-1) - col;
//     int bottomRightDiff = smallerDifference(bottomRightRowDiff, bottomRightColDiff);
//     while(bottomRightDiff--){
//             visited[++p][++k] = ".";
//     }
    
//     // Marking Current Row Visited
//     for(int colItr=0; colItr<N; colItr++){
//         if(colItr != col){
//             visited[row][colItr] = ".";
//         }
//     }
//     // Marking Current Column Visited
//     for(int rowItr=0; rowItr<N; rowItr++){
//         if(rowItr != row){
//             visited[rowItr][col] = ".";
//         }
//     }

//     visited[row][col] = "Q";
//     cnt++;

//     if(cnt == N){
//         display(visited);
//         return true;
//     }; 
    
//     for(int colItr = 0; colItr<N; colItr++){
//         if((row+1<=N) && (visited[row+1][colItr]=="-1")){
//             if(nQueens(visited, cnt, row+1, colItr, N))return true;
//             // visited[row+1][colItr] = "-1";
//         }
//     }
//     visited[row][col] = ".";
//     return false;
// }

bool isSafe(vector<string>&board, int row, int col, int N){
    int duprow = row;
    int dupcol = col;

    // We are going col-by-col, which gives us insights that
    // Whenever a new queen is placed she has some chances of
    // being attacked from the left-half side and 0 chances of being 
    // attacked from the right side

    // Check the presence of queen in relative top-left diagonal
    // Time Complexity: O(N)
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;

    // Check the presence of queen in relative left side of 
    // the current row
    // Time Complexity: O(N)
    while(col>=0){
        if(board[row][col] == 'Q')return false;
    }

    col = dupcol;
    row = duprow;

    // Check the presence of queen in relative bottom-left diagonal
    // Time Complexity: O(N)
    while(row<N && col>=0){
        if(board[row][col] == 'Q')return false;
    }

    return true;
}

// Overall Time Complexity: O(N*(O(N)+O(N)+O(N))) --> O(3N*N)
// wiz not good so time to optimization
void nQueens_avgSolution(vector<string>&board, vector<vector<string>>&ans, int col, int N){
    if(col == N){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<N; row++){
        if(isSafe(board, row, col, N)){
            board[row][col] = 'Q';
            nQueens_avgSolution(board, ans, col+1, N );
            board[row][col] = '.';
        }
    }
}

void hashingQueenOccurance(vector<string>&board, vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int row, int col, int N){
    board[row][col] = 'Q';
    leftRow[row] = 1;
    upperDiagonal[(N-1)+(col-row)] = 1;
    lowerDiagonal[row+col] = 1;
}

void unHashingQueenOccurance(vector<string>&board, vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int row, int col, int N){
    board[row][col] = '.';
    leftRow[row] = 0;
    upperDiagonal[(N-1)+(col-row)] = 0;
    lowerDiagonal[row+col] = 0;
}

void nQueens_bestSolution(vector<vector<string>>&ans, vector<string>&board, vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int col, int N){
    if(col == N){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<N; row++){
        if(leftRow[row] == 0 && upperDiagonal[(N-1)+(col-row)] == 0 && lowerDiagonal[row+col] == 0){
            hashingQueenOccurance(board, leftRow, upperDiagonal, lowerDiagonal, row, col, N);
            nQueens_bestSolution(ans, board, leftRow, upperDiagonal, lowerDiagonal, col+1, N);
            unHashingQueenOccurance(board, leftRow, upperDiagonal, lowerDiagonal, row, col, N);
        }
    }
}


int main(){
    int N;
    cout<<"Enter the side of chessboard: "<<endl;
    cin>>N;

    
    // for(int row=0; row<1; row++){
    //     for(int col=0; col<N; col++){
        
    //         vector<vector<string>>visited(N, vector<string>(N,"-1"));
    //         bool ans = nQueens(visited, 0, row, col, N);
    //         // if(ans){
    //         //     display(visited);
    //         // }            
    //     }
    // }
    vector<string>board(N);
    string s(N, '.');
    for(int i=0; i<N; i++){
        board[i] = s;
    }
    vector<vector<string>>ans;
    // nQueens_avgSolution(board, ans, 0, N);

    vector<int>leftRow(N,0);
    vector<int>upperDiagonal(2*N-1, 0);
    vector<int>lowerDiagonal(2*N-1, 0);
    nQueens_bestSolution(ans, board, leftRow, upperDiagonal, lowerDiagonal, 0, N);
    display(ans);
    cout<<"Printing the total count of solutions: "<<ans.size()<<endl;

    return 0;
}