//Problem Link: https://bit.ly/3pya8CP

#include<bits/stdc++.h>
int dp[101][101];
int lcs(int i,int j,string &s1,string &s2){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s1[i]==s2[j]){
        return 1+lcs(i-1,j-1,s1,s2);
    }
    
    return dp[i][j]=max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
    
}
int canYouMake(string &str, string &ptr){
    memset(dp,-1,sizeof(dp));
    int n=str.length();
    int m=ptr.length();
    return n+m-2*lcs(n-1,m-1,str,ptr);
    //return n+m-2*ans;
}