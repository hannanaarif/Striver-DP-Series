//https://bit.ly/3q5rlUY


//Approch 1

#include<bits/stdc++.h>
int dp[10005];
int helper(int size,vector<int> &nums){
    if(size==0){
        return nums[size];
    }
    if(size<0){
        return 0;
    }
    if(dp[size]!=-1){
        return dp[size];
    }
    return dp[size]= max(helper(size-1,nums),helper(size-2,nums)+nums[size]);
}
int maximumNonAdjacentSum(vector<int> &nums){
    memset(dp,-1,sizeof(dp));
    int n=nums.size();
    //vector<int> dp(n,-1);
    return helper(n-1,nums);
}


//Approch 2


int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
            //dp[i]=max(if(i>1){nums[i]+dp[i-2]},dp[i-1]);
        int take=nums[i];if(i>1) take+=dp[i-2];
        int nottake=dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}