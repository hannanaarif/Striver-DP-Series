#include<bits/stdc++.h>
int dp[20][20];
int helper(int i,int j){
	if(i==0 &&j==0){
		return 1;
	}
	if(i<0 ||j<0){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int up=helper(i-1,j);
	int left=helper(i,j-1);
	return dp[i][j]=up +left;
}
int uniquePaths(int m, int n) {
    memset(dp,-1,sizeof(dp));
	return helper(m-1,n-1);
}