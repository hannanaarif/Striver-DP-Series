//Problem Link: https://bit.ly/3B5JBkU

#include<bits/stdc++.h>
int dp[1001][1001];
int helper(int ind,int tar,vector<int>&nums){
    if(tar==0) return 1;
    if(ind==0)
        return nums[0]==tar;
    
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }
    
    int NotTake=helper(ind-1,tar,nums);
    int take=0;
    if(nums[ind]<=tar) 
    take=helper(ind-1,tar-nums[ind],nums);
    
    return dp[ind][tar]=NotTake+take;
    
}
int findWays(vector<int> &num, int tar){
    memset(dp,-1,sizeof(dp));
    int n=num.size();
    return helper(n-1,tar,num);
}
