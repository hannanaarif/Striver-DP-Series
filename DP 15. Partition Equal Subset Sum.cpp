//https://bit.ly/34iIIsH

#include<bits/stdc++.h>
int dp[105][10005];
bool EqualSubsetSum(int i,int target,vector<int> &arr){
   
    if(target==0){
        return true;
    }
     
    if(i<0){
        if(target==0){
            return true;
        }
        return false;
    } 
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool take=false;
    if(arr[i]<=target){
        take=EqualSubsetSum(i-1,target-arr[i],arr);
    }
    bool nottake=EqualSubsetSum(i-1,target,arr);

    return dp[i][target]=take||nottake;    
}

bool canPartition(vector<int> &arr, int n){
    memset(dp,-1,sizeof(dp));
    int target=0;
     for(int i=0;i<n;i++){
         target+=arr[i];
     }
    if(target/2==0 || target%2){
        return false;
    }
    else{
        return EqualSubsetSum(n-1,target/2,arr);
    }   
}
