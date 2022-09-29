//Problem Link: https://bit.ly/3qXtORt
#include<bits/stdc++.h>
int dp[201][201];
bool solve(int i,int j,string &pattern,string &text){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for(int j=0;j<=i;j++){
            if(pattern[j]!='*'){
                return false;
            }
            return true;
        }
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return dp[i][j]=solve(i-1,j-1,pattern,text);
    }
    if(pattern[i]=='*'){
      return  dp[i][j]=solve(i-1,j,pattern,text) || solve(i,j-1,pattern,text); 
    }
    return dp[i][j]=false;
}
bool wildcardMatching(string pattern, string text){
    memset(dp,-1,sizeof(dp));
    int n=pattern.size();
    int m=text.size();
    return solve(n-1,m-1,pattern,text);
}
