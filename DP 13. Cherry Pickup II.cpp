#include<bits/stdc++.h>
int dp[52][52][52];
int solve(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid){
    if(j1<0 || j1>=c || j2<0 || j2>=c) {
        return -1e9;  
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    if(i==r-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    int ans=-1e9;
    for(int am=-1;am<=1;am++){
        for(int bm=-1;bm<=1;bm++){
            int value=0;
            if(j1==j2){
                value=grid[i][j1];
            }
            else{
                value=grid[i][j1]+grid[i][j2];
            }
            value+=solve(i+1,j1+am,j2+bm,r,c,grid);
            ans=max(ans,value);
        }
    }
    return dp[i][j1][j2]=ans;  
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    memset(dp,-1,sizeof(dp));
    return solve(0,0,c-1,r,c,grid);
}