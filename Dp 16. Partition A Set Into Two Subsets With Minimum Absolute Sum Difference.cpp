//https://bit.ly/3t62bqQ

#include<bits/stdc++.h>
int dp[1005][10005];

int solve(vector<int> &arr,int ind,int presum,int sum){
     if(ind==0)
         return abs(sum-2*presum);
    
     if(dp[ind][presum]!=-1)
         return dp[ind][presum];
    
    int nottaken = solve(arr,ind-1,presum,sum);
    
    int taken = solve(arr,ind-1,presum+arr[ind],sum);
    
    return dp[ind][presum] = min(nottaken,taken);
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    memset(dp,-1,sizeof(dp));
    int sum =0;
    
    for(int i = 0;i<n;i++)
        sum+=arr[i];
    
    return solve(arr,n-1,0,sum);
}
