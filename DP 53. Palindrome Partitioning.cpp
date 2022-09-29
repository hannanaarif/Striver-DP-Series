//https://bit.ly/3jNRzqX

#include <bits/stdc++.h> 
int dp[101];
bool isPalindrome(int i,int j,string str){
 while(i<j){
    if(str[i]!=str[j]){
        return false;
    }
        i++;
        j--;
    }
    return true;
}
int solve(int i, int j,string &str){
    if(i==j){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int cost, mincost=1e9;
    for(int k=i;k<j;k++){
         if(isPalindrome(i,k,str)){
             cost=1+solve(k+1,j,str);
             mincost=min(mincost,cost);
         }     
    }
    return  dp[i]=mincost;
}
int palindromePartitioning(string str) {
    memset(dp,-1,sizeof(dp));
    int n=str.size();
    return solve(0,n,str)-1;
}
