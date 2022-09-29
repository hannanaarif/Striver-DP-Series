//https://bit.ly/33Kd8o2
#include<bits/stdc++.h>
long long dp[20][3000];
long long solve(long long i,long long val,int *den){
//     if(val==0){
//         return 1;
//     }
    if(i==0){
        return (val%den[0]==0);
//         if(val==0){
//             return 1;
//         }
//         return den[0]==val?1:0;
    }
    if(dp[i][val]!=-1){
        return dp[i][val];
    }
    long long ntake=solve(i-1,val,den);
    long long take=0;
    if(den[i]<=val){
       take=solve(i,val-den[i],den);
    }
    return dp[i][val]=ntake+take; 
}
long long countWaysToMakeChange(int *denominations, int n, int value){
    memset(dp,-1,sizeof(dp));
    return solve(n-1,value,denominations);
}