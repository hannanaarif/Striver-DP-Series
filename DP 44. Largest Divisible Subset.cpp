/*
https://leetcode.com/problems/largest-divisible-subset/

368. Largest Divisible Subset
Medium
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], 
answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<int> dp(nums.size(),1);
       vector<int> hash(nums.size(),-1);
        int max_ans = INT_MIN;
        int max_ind = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0) && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                   hash[i] = j;
                }
            }
            if(max_ans<dp[i]){
                max_ans = dp[i];
                max_ind = i;
            }
        }
        vector<int> ans;
       // cout<<dp[max_ind];
        while(max_ind != -1){
            ans.push_back(nums[max_ind]);
            max_ind = hash[max_ind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

