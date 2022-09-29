// https://bit.ly/3HJTeIl

#include<bits/stdc++.h>
int dp[16][10005];
int solve(int i,int tar,vector<int> &num){
   if(i==0){
       if(tar%num[0]==0){
           return tar/num[0];
       }
       else{
         return 1e9;
       }
   }
    if(dp[i][tar]!=-1){
        return dp[i][tar];
    }
    int notake=solve(i-1,tar,num);
    int take=1e9;
    if(num[i]<=tar){
        take=1+solve(i,tar-num[i],num);
    }
    return dp[i][tar]=min(take,notake);
}
int minimumElements(vector<int>&num, int x){
    memset(dp,-1,sizeof(dp));
    int n=num.size();
    int ans= solve(n-1,x,num);
    if(ans>=1e9){
        return -1;
    }
    return ans;
}