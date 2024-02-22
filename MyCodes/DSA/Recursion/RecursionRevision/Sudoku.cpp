#include<iostream>
#include<vector>
#include<string>

using namespace std;

// void insertPossibleNumber(vector<vector<string>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int p, int q, int x, int N){
//     int r = 2*x + (p+q);
//     for(int num=1; num<=9; num++){
//         if(rowHashMap[p][num]==0 && colHashMap[q][num] ==0 && subMatrixHashMap[r][num]==0){
//             sudokuMatrix[p][q] = num;
//         }
//     }
// }

void sudokuSolver(vector<vector<string>>&sudokuMatrix, vector<vector<int>>&rowHashMap, vector<vector<int>>&colHashMap, vector<vector<int>>&subMatrixHashMap, int x, int cnt, int N){
    

    for(int y=0; y<N; y++){
        int p = 3*(x/3)+ (y/3);
        int q = 3*(x%3) + (y%3);
        cnt++;
        if(sudokuMatrix[p][q]=="."){
            x = cnt/9;
            // insertPossibleNumber();
            int r = 2*x + (p+q);
            for(int num=1; num<=9; num++){
                if(rowHashMap[p][num]==0 && colHashMap[q][num] ==0 && subMatrixHashMap[r][num]==0){
                    sudokuMatrix[p][q] = to_string(num);
                    sudokuSolver(sudokuMatrix, rowHashMap, colHashMap, subMatrixHashMap, x, cnt, N);
                    sudokuMatrix[p][q] = ".";
                }
            }

        }
    }
}

int main(){

    vector<vector<int>>rowHashMap(9, vector<int>(10, 0));
    vector<vector<int>>colHashMap(9, vector<int>(10, 0));
    vector<vector<int>>subMatrixHashMap(9, vector<int>(10,0));
    vector<vector<string>>sudokuMatrix(9, vector<string>(9, ""));

    int N = 9;
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            string s;
            cin>>s;
            sudokuMatrix[row][col] = s;
            if(s!="."){
                int num = stoi(s);
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

    for(int row=0; row<N; row++){
        int cnt = 0;
        for(int col=0; col<N; col++){
            int p = row/3;
            int q = col/3; 
            int r = (row/3)*2 + p+q;    
            cout<<"("<<p<<", "<<q<<", "<<row<<") ";

        }
        cout<<"\n"<<endl;
    }

    return 0;
}