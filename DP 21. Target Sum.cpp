//https://bit.ly/3swy5uL
int help(int i,int d,vector<int>&arr){
   if(i==0){
       return d==0?1:0;
   }
   int not_take=help(i-1,d,arr);
   int take=0;
   if(arr[i]<=d)
      take=help(i-1,d-arr[i],arr);  
   return not_take+take;
}
int targetSum(int n, int target, vector<int>& arr) {
   target=abs(target);
   int sum=0;
   for(int child:arr) sum+=child;
   if(target>sum||(target+sum)%2) return 0;
   int d=(sum+target)/2;
   return help(arr.size()-1,d,arr);
}