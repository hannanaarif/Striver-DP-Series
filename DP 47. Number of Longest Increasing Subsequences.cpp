//https://bit.ly/3fTRGiz

#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr){
    int n =arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    int maxi=0,ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];
            }
            else if(arr[j]<arr[i] && 1+dp[j]==dp[i]){
                dp[i]=dp[j]+1;
                cnt[i]+=cnt[j];   
            }
        }
        maxi=max(maxi,dp[i]);
    }
    for(int i=0;i<n;i++){
        if(maxi==dp[i]){
            ans+=cnt[i];
        }
    }
    return ans;
}