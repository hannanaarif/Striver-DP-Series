#include<bits/stdc++.h>
using namespace std;
int n,m;
string solve(string s1,string s2){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<=m;i++){
    	dp[0][i]=0;
    }
    for(int j=0;j<=n;j++){
    	dp[j][0]=0;
    }

    for(int i=1;i<=n;i++){

    	for(int j=1;j<=m;j++){

    		if(s1[i-1]==s2[j-1]){

    			dp[i][j]=1+dp[i-1][j-1];
    		}

    		else{

    			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    		}	
    	}
    }
    // int len=dp[n][m];
    string ans="";
    // for(int i=0;i<len;i++){
    // 	ans+='$';
    // }
    // int index=len-1;
    int i=n,j=m;
    while(i>0 && j>0){
    	if(s1[i-1]==s2[j-1]){
    		ans+=s1[i-1];
    		//index--;
    		i--;
    		j--;
    	}
    	else if(dp[i-1][j]>dp[i][j-1]){
    		i--;
    	}
    	else{
    		j--;
    	}
    }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif



string s1,s2;
cin>>s1;
cin>>s2;
n=s1.length();
m=s2.length();
cout<<solve(s1,s2);
}