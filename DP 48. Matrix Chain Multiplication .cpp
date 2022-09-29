// https://bit.ly/3nXqfce

#include <bits/stdc++.h> 
int dp[101][101];
int solve(int i,int j,vector<int>&arr){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr)+solve(k+1,j,arr);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N){
    memset(dp,-1,sizeof(dp));
    return solve(1,N-1,arr);
}