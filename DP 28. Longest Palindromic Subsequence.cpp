//https://bit.ly/3BuCCDD
#include<bits/stdc++.h>
int dp[101][101];
int solve(int i,int j,string &s1,string &s2){
    if(i<0||j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return 1+solve(i-1,j-1,s1,s2);
    }
    
    return dp[i][j]=max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
}
int longestPalindromeSubsequence(string s){
    memset(dp,-1,sizeof(dp));
    string s1=s;
    reverse(s1.begin(),s1.end());
    int n=s.length()-1;
    return solve(n,n,s,s1);
    
}