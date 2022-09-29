//Problem Link: https://bit.ly/3rVoIoq

#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int insertAt[n];
    vector<int> lis;
    //lis.push_back(arr[0]);
    for(int i=0;i<n;i++){
        if(lis.empty()||lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertAt[i]=lis.size();
        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            *it=arr[i];
            insertAt[i]=it-lis.begin()+1;
        }
    }
    cout<<lis.size();
    cout<<"\n";
    int cursize=lis.size();
    vector<int> final;
    for(int i=n-1;i>=0;i--){
    	if(insertAt[i]==cursize){
    		final.push_back(arr[i]);
    		cursize--;
    	}
    }

  reverse(final.begin(),final.end());
  for(auto it:final){
  	cout<<it<<" ";
  }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	     #endif
	int t=1;
	while(t--){

		solve();
	}
}