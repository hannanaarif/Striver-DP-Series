#include<bits/stdc++.h>
int dp[205][205];
int solve(int n, int m, vector< vector< int> > &mat){
    if(n>=0 && m>=0 && mat[n][m]==-1){
        return 0;
    }
    if(n==0&&m==0){
        return 1;
    }
    if(n<0||m<0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    int ans=solve(n-1,m,mat)+solve(n,m-1,mat);
    return dp[n][m]=ans;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat){
    memset(dp,-1,sizeof(dp));
    return solve(n-1,m-1,mat);
}
