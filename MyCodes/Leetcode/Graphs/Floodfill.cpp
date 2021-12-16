#include <iostream>
#include <vector>
using namespace std;

// const int N = 1e3 +5;
// const int M = 1e3 +5;

// struct co_Ord{
//     int x;
//     int y;
// }

void DFS(int i, int j, int initialColor, int newColor, vector<vector<int>> &image){
    int n = image.size();
    int m = image[0].size();
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!= initialColor) return;

    image[i][j] = newColor;

    DFS(i-1, j, initialColor, newColor, image);
    DFS(i+1, j, initialColor, newColor, image);
    DFS(i, j-1, initialColor, newColor, image);
    DFS(i, j+1, initialColor, newColor, image);
}

class Solution {
public:
    vector<vector<int>> input(int n, int m);
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
    void print(vector<vector<int>> &image);
};

vector<vector<int>> Solution::input(int n, int m){
    
    vector<vector<int>> image(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>image[i][j];
        }
    }
    return image;
}

vector<vector<int>> Solution::floodFill(vector<vector<int>> & image, int sr, int sc, int newColor){
    int initialColor = image[sr][sc];
    if(initialColor!=newColor){
        DFS(sr, sc, initialColor, newColor, image);
    }
    return image;
}

void Solution::print(vector<vector<int>> &image){
    cout<<"\nPrinting the updated graph..."<<endl;
    for(int i=0; i<image.size(); i++){
        for(int j=0; j<image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int sr,sc,newColor;
    cin>>sr>>sc>>newColor;

    int n,m;
    cin>>n>>m;

    vector<vector<int>>image(n, vector<int>(m));
    
    Solution sol_obj;
    
    image = sol_obj.input(n, m);
    sol_obj.floodFill(image, sr, sc, newColor);
    sol_obj.print(image);
    
    return 0;
}