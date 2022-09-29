//https://bit.ly/3Kgck9N
#include <bits/stdc++.h> 
int dp[101][101];
int solve(int i,int j,vector<int>arr){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxi=-1e9;
    for(int k=i;k<=j;k++){
        int cost=arr[i-1]*arr[k]*arr[j+1]+solve(i,k-1,arr)+solve(k+1,j,arr);
        maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
int maxCoins(vector<int>& a){
    memset(dp,-1,sizeof(dp));
	int n=a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    return solve(1,n,a);
}