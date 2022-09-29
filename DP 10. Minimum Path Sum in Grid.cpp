#include<bits/stdc++.h>
int dp[105][105];
int solve(int i,int j,vector<vector<int>> &grid){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j< 0){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    return dp[i][j]=min(grid[i][j]+solve(i-1,j,grid),grid[i][j]+solve(i,j-1,grid));
}

int minSumPath(vector<vector<int>> &grid) {
    memset(dp,-1,sizeof(dp));
    int n=grid.size();
    int m=grid[0].size();
    return solve(n-1,m-1,grid);
}