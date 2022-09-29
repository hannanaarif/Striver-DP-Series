#define mod 1000000007
int dp[51][51];
int solve(int i,int n,int target,vector<int>&arr){
    if(target==0){
        return 1;
    }
    
    if(i==n){
        return target==0?1:0;
    }
    if(dp[i][target]!=-1){
        return dp[i][target]%mod;
    }

    int notake=solve(i+1,n,target,arr);

    int take=0;
    if(arr[i]<=target){
        take=solve(i+1,n,target-arr[i],arr);
    }
     return dp[i][target]=(take+notake)%mod;
}
int countPartitions(int n, int d, vector<int> &arr){
    memset(dp,-1,sizeof(dp));
    int totalsum=0;
    for(int i=0;i<=n;i++){
        totalsum+=arr[i];
    }
    int target=(totalsum-d)/2;
    if(target-d<0 || target%2){
        return 0;
    }
    return solve(0,n,target,arr);
}


