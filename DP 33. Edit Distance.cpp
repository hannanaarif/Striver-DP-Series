//Problem Link: https://bit.ly/3HcTJdy

#include<bits/stdc++.h>
int dp[1001][1001];
int solve(int i,int j,string &s1, string &s2){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=solve(i-1,j-1,s1,s2);
    }
 return dp[i][j]=1+min({solve(i-1,j,s1,s2),solve(i,j-1,s1,s2),solve(i-1,j-1,s1,s2)});
}

int editDistance(string str1,string str2){
    memset(dp,-1,sizeof(dp));
    int n=str1.length();
    int m=str2.length();
    return solve(n-1,m-1,str1,str2);
}