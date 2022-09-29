#include<bits/stdc++.h>
int dp[1001][1001];
bool subset(int i,int target,vector<int> &arr){
     if(target==0){
        return true;
     }
    
    if(i<0){
        if(target==0){
            return true;
        }
        else{
            return false;
        }
    } 
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool take=false;
    if(arr[i]<=target){
           take=subset(i-1,target-arr[i],arr);
    }
    bool nottake=subset(i-1,target,arr);
    
     return dp[i][target]= take||nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    memset(dp,-1,sizeof(dp));
     return subset(n-1,k,arr);
//     if(ans){
//         return true;
//     }
//     else{
//         return false;
//     }
}