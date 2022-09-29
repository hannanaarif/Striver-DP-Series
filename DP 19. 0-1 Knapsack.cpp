//https://bit.ly/3KHpP3v
#include<bits/stdc++.h>
int dp[105][1005];
int solve(int i,int n,vector<int> &weight,vector<int>&value,int maxWeight){
    if(i==n){
        return 0;
    }
    if(dp[i][maxWeight]!=-1){
       return dp[i][maxWeight]; 
    }
    int notake=solve(i+1,n,weight,value,maxWeight);
    int take=0;
    if(weight[i]<=maxWeight){
        take=solve(i+1,n,weight,value,maxWeight-weight[i])+value[i];
    }
    return dp[i][maxWeight]=max(take,notake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    memset(dp,-1,sizeof(dp));
    return solve(0,n,weight,value,maxWeight);
}