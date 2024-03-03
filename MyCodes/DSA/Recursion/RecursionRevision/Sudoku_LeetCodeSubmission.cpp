class Solution {
public:
    void hashingNumOccurence(vector<vector<char>>&board, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int p, int q, int x, int r, int num, int N){
    board[p][q] = '0' +(num);
    rowHashMap[p][num] = 1;
    colHashMap[q][num] = 1;
    subMatrixHashMap[r][num] = 1;
}

    void unHashingNumOccurence(vector<vector<char>>&board, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int p, int q, int x, int r, int num, int N){
    board[p][q] = '.';
    rowHashMap[p][num] = 0;
    colHashMap[q][num] = 0;
    subMatrixHashMap[r][num] = 0;
}

    bool sudokuSolver_better(vector<vector<char>>&board, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int x, int y, int cnt, int N){
    // Base Condition
    if(x==9 || y== 81)return true;

    int itr = y%9;

    int p = 3*(x/3)+ (itr/3);
    int q = 3*(x%3) + (itr%3);

    if(board[p][q]=='.'){
        int r = 2*(p/3) + (p/3) +(q/3);

        for(int num=1; num<=9; num++){

            if(rowHashMap[p][num]==0 && colHashMap[q][num]==0){
                       
                if(subMatrixHashMap[r][num]==0){        
                    
                    hashingNumOccurence(board,rowHashMap, colHashMap, subMatrixHashMap, p, q, y/9, r, num, N);
                    if(sudokuSolver_better(board, rowHashMap, colHashMap, subMatrixHashMap, (y+1)/9, y+1, cnt+1, N)){
                        return true;
                    }           
                    unHashingNumOccurence(board, rowHashMap, colHashMap, subMatrixHashMap, p, q, y/9, r, num, N);                    
                }
            }
        }
        return false;

    }
    if(sudokuSolver_better(board, rowHashMap, colHashMap, subMatrixHashMap, (y+1)/9, y+1, cnt+1, N)){
        return true; 
    }
    return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
    vector<vector<int>>rowHashMap(9, vector<int>(10, 0));
    vector<vector<int>>colHashMap(9, vector<int>(10, 0));
    vector<vector<int>>subMatrixHashMap(9, vector<int>(10,0));
    int N = 9;
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            char c = board[row][col];
            
            if(c!='.'){
                int num = (c) - '0';
                rowHashMap[row][num] = 1;
                colHashMap[col][num] = 1;

                int p = row/3;
                int q = col/3;
                int r = (row/3)*2 + p+q;

                subMatrixHashMap[r][num] = 1;
            }
        }
    }
    
    sudokuSolver_better(board, rowHashMap, colHashMap, subMatrixHashMap, 0, 0, 0, N);
    } 
};