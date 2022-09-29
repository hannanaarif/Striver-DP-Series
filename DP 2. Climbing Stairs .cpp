//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int dp[50];
    int N;
    int rec(int level){
        //pruning
        if(level>N)return 0;
        
        //base case
        if(level==N){
            return 1;
        }
        
        //cache check
        if(dp[level]!=-1)return dp[level];
        
        //compute
        int ans=0;
        ans+=rec(level+1);
        ans+=rec(level+2);
        
        //save and return
        return dp[level]=ans;
    }
    
    int climbStairs(int n) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};