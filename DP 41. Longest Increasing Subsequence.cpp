//Problem Link: https://bit.ly/3rVoIoq

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(lis.empty()||lis.back()<arr[i]){
            lis.push_back(arr[i]);
        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            *it=arr[i];
        }
    }
  return lis.size();
}