//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
int h[100005];
int dp[100005];
int solve(int i,int k){
	if(i==0){
		return 0;
	}
// 	if(i<0){
// 		return 1e9;
// 	}
	//int jump=0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int minstep=1e9;

	for(int j=1;j<=k;j++){
		if(i-j>=0){
			minstep=min(minstep,solve(i-j,k)+abs(h[i]-h[i-j]));
		}
	//	minstep=min(jump,minstep);
	}
   return dp[i]=minstep;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	     #endif
	int N,K;
	memset(dp,-1,sizeof(dp));
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>h[i];
	}
	cout<<solve(N-1,K);
}

