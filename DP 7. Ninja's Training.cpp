//https://bit.ly/3F4yl8z

#include<bits/stdc++.h>
int dp[100005][4];
int solve(int i,int last,vector<vector<int>> &points){
    if(i==0){
        int maxi=0;
        for(int j=0;j<3;j++){
            if(j!=last){
                maxi=max(maxi,points[0][j]);
            }
        }
        return maxi;
    }
    if(dp[i][last]!=-1){
        return dp[i][last];
    }
    int maxi=0;
    for(int j=0;j<3;j++){
        if(j!=last){
            int point=solve(i-1,j,points)+points[i][j];
            maxi=max(point,maxi);
        }  
    }
    return dp[i][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    memset(dp,-1,sizeof(dp));
    return solve(n-1,3,points);
}


