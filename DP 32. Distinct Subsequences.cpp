//Problem Link: https://bit.ly/3nZNxy7
//https://leetcode.com/problems/distinct-subsequences/submissions/

#include<bits/stdc++.h>
#define mod 1000000007
int dp[1005][1005];
int solve(int i,int j,string &s1,string &s2){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=(solve(i-1,j-1,s1,s2)%mod+solve(i-1,j,s1,s2)%mod)%mod;
    }
    return dp[i][j]=solve(i-1,j,s1,s2)%mod;
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    memset(dp,-1,sizeof(dp));
   int n=t.size();
   int m=s.size();
   return solve(n-1,m-1,t,s)%mod;
} 