//Problem Link: https://bit.ly/3H10kYJ

#include<bits/stdc++.h>
int dp[101][101];
int solve(int i,int n,vector<int> &price){
    if(i==0){
        return n*price[i];
    }
    if(dp[i][n]!=-1){
        return dp[i][n];
    }
    int ntake=solve(i-1,n,price);
    int take=-1e9;
    int rod_len=i+1;
    if(rod_len<=n){
        take=price[i]+solve(i,n-rod_len,price);
    }
    return dp[i][n]=max(ntake,take);
}

int cutRod(vector<int> &price, int n){
    memset(dp,-1,sizeof(dp));
    int i=price.size()-1;
    return solve(i,n,price);
}