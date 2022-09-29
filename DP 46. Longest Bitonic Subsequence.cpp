// https://bit.ly/3r4o1JB

#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp(n,1);
    vector<int> dp1(n,1);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
     for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j] && dp1[i]<dp1[j]+1){
                dp1[i]=dp1[j]+1;
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]+dp1[i]-1);
    }
    return maxi;
} 
