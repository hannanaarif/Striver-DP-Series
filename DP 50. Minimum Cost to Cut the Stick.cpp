//https://bit.ly/3rWLMnC

#include<bits/stdc++.h>
int dp[1001][1001];
int helper(int i,int j,vector<int> &cuts){
	if(i>j) return 0;
	int mini=1e9;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	for(int k=i;k<=j;k++){
	int cost=cuts[j+1]-cuts[i-1]+helper(i,k-1,cuts)+helper(k+1,j,cuts);
	mini=min(mini,cost);	
	}
	return dp[i][j]=mini;
}
int cost(int n, int c, vector<int> &cuts){
    memset(dp,-1,sizeof(dp));
    cuts.push_back(n);
	cuts.insert(cuts.begin(),0);
	sort(cuts.begin(),cuts.end());
	//vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
	return helper(1,c,cuts);
}