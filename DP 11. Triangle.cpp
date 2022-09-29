#include<bits/stdc++.h>
int dp[1000][1000];
int solve(int i,int j,vector<vector<int>>& triangle,int n){
    if(i==n){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=min(triangle[i][j]+solve(i+1,j,triangle,n),triangle[i][j]+solve(i+1,j+1,triangle,n));
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    memset(dp,-1,sizeof(dp));
	return solve(0,0,triangle,n-1);
}