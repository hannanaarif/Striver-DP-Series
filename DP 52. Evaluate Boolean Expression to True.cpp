// https://bit.ly/32tAMUW
#include <bits/stdc++.h> 
int dp[201][201][2];
#define mod 1000000007
long long solve(int i,int j,int isTrue,string & exp){
    if(i>j){
        return 0;
    }
    if(i==j){
        
        if(isTrue){
            return exp[i]=='T';
        }
       else{
           return exp[i]=='F';
       } 
    }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    long long ways=0;
    for(int k=i+1;k<=j-1;k=k+2){
        long long lt=solve(i,k-1,1,exp);
        long long lf=solve(i,k-1,0,exp);
        long long rt=solve(k+1,j,1,exp);
        long long rf=solve(k+1,j,0,exp);
        if(exp[k]=='&'){  
           if(isTrue)
               ways=(ways+(lt*rt)%mod)%mod;
           else
               ways=(ways+(lt*rf)%mod+(rt*lf)%mod+(rf*lf)%mod)%mod;
        }
        else if(exp[k]=='|'){
            
            if(isTrue){
                ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
            }
            else{
                ways=(ways+(rf*lf)%mod)%mod;
            }   
        }
        else{  
            if(isTrue){
                ways=(ways+(rt*lf)%mod+(lt*rf)%mod)%mod;
            }
            else{
                ways=(ways+(rf*lf)%mod+(rt*lt)%mod)%mod;
            }
        }
    }
   return dp[i][j][isTrue]=ways;   
}
int evaluateExp(string & exp){
    memset(dp,-1,sizeof(dp));
    int n=exp.size();
    return solve(0,n-1,1,exp);
}