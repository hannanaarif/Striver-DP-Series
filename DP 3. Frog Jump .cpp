//https://bit.ly/3JPcoOx

#include <bits/stdc++.h> 
int dp[100005];
int solve(int n, vector<int> &heights){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left=solve(n-1,heights)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;    
    if(n>1){
       right=solve(n-2,heights)+abs(heights[n]-heights[n-2]);  
    }
    return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights){ 
    memset(dp,-1,sizeof(dp));
    return solve(n-1,heights);
}