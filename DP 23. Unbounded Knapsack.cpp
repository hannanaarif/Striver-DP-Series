//https://bit.ly/3IvPdXS.
#include<bits/stdc++.h>
int dp[1001][1001];

int solve(int i,int w,vector<int> &profit,vector<int> &weight){
    if(i==0){
        return (w/weight[0])*profit[0];
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    int ntake=solve(i-1,w,profit,weight);
    int take=-1e9;
    if(weight[i]<=w){
        take=profit[i]+solve(i,w-weight[i],profit,weight);
    }
    return dp[i][w]=max(ntake,take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){ 
    memset(dp,-1,sizeof(dp));
    return solve(n-1,w,profit,weight);
}
