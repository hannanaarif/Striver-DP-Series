#include<bits/stdc++.h>
int dp[105][105];
int solve(int i,int j,vector<vector<int>> &matrix){
    if(j<0 || j>=matrix[0].size()){
        return -1e8;
    }
    if(i==0){
        return matrix[0][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
//     int u=matrix[i][j]+solve(i-1,j,matrix);
//     int v=matrix[i][j]+solve(i-1,j-1,matrix);
//     int w=matrix[i][j]+solve(i-1,j+1,matrix);
//     return dp[i][j]=max(u,max(v,w));
    
    return dp[i][j]=max({matrix[i][j]+solve(i-1,j,matrix),  matrix[i][j]+solve(i-1,j-1,matrix),   matrix[i][j]+solve(i-1,j+1,matrix)});
}

int getMaxPathSum(vector<vector<int>> &matrix){
     memset(dp,-1,sizeof(dp));
     int n=matrix.size();
     int m=matrix[0].size();
     int ans=-1e18;
     for(int j=0;j<m;j++){
        ans=max(ans,solve(n-1,j,matrix));
     }
    return ans;
}