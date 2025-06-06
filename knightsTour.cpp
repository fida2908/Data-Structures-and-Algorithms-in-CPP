#include <iostream>
#include <vector>
using namespace std;

bool knightsTour(vector<vector<int>> &grid, int r, int c, int n, int expVal){
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal ){
        return false;
    }

    if(expVal == n*n - 1){
        return true;
    }

    return  knightsTour(grid,r+1,c+2,n,expVal+1) ||
            knightsTour(grid,r+1,c-2,n,expVal+1) ||
            knightsTour(grid,r-1,c+2,n,expVal+1) ||
            knightsTour(grid,r-1,c-2,n,expVal+1) ||
            knightsTour(grid,r+2,c+1,n,expVal+1) ||
            knightsTour(grid,r+2,c-1,n,expVal+1) ||
            knightsTour(grid,r-2,c+1,n,expVal+1) ||
            knightsTour(grid,r-2,c-1,n,expVal+1); 
}

int main(){
    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};
    cout << (knightsTour(grid,0,0,grid.size(),0) ? "true" : "false");

    return 0;
}