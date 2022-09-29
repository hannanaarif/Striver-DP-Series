//Problem Link: https://bit.ly/3pvkqUd

#include<bits/stdc++.h>
int dp[1005][1005];
int solve(int i,int j,string &s,string &t){
    if(i<0||j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return 1+solve(i-1,j-1,s,t);
    }
    return dp[i][j]=max(solve(i-1,j,s,t),solve(i,j-1,s,t));  
}
int lcs(string s, string t){
    memset(dp,-1,sizeof(dp));
	int n=s.length()-1;
    int m=t.length()-1;
    return solve(n,m,s,t);
}