/*Problem Link: https://bit.ly/3KHsl9J

Longest String Chain


You are given an array ' ARR ' of strings , where each string consists of

English lowercase letters.

Let's say a string ' A ' is a predecessor of string ' B ' if and only 
if we can add exactly one letter
anywhere in ' A ' to make it equal to ' B ' . For example " abd " is a predecessor of " abcd " , we can add " c "
in " abd " to make a string " abcd "
A string chain is a sequence of strings where for every ' i ' in [ 1 ... ( K - 1 ) ] , ' S ; ' is the predecessor of
' Si + 1 ' . And the length of such a string chain is ' K ' .
Now your task is to find the length of the longest possible string chain .

For Example :


For Example :

  Let ' ARR ' = [ " x " , " xx " , " y " , " xyx " ]

  The longest possible string chain is " x " - > " xx " - > " xyx "

  The length of the given chain is 3 , hence the answer is 3 .

Input Format :
  The first line contains a single integer ' T ' denoting the number of test cases , then each
  test case follows :
  The first line of each test case contains a single integer ' N ' denoting the length of the
  array .
  The following line contains ' N ' space - separated strings .


Output Format :
  For each test case , find the length of the longest possible string chain with strings
  chosen from the given array .
  Output for each test case will be printed on a separate line .
Note :
  You are not required to print anything ; it has already been taken care of . Just implement
  the function .


Constraints :
  1 ≤ T ≤ 10
  1 ≤ N ≤ 300
  1 WORDS [ i ] .length ≤ 16
  Time limit : 1 sec


Sample Input 1 :
2
4
x xx y xyx
3
m nm mmm

Sample Output 1 :
3
2

Explanation For Sample Input 1 :
For test case 1 :
We will print 3 because:
The longest possible string chain is “x” -> “xx” -> “xyx”.
The length of the given chain is 3, hence the answer is 3.

For test case 2 :
We will print 2 because:
The longest possible string chain is “m” -> “nm”.
The length of the given chain is 2, hence the answer is 2.
Sample Input 2 :
2
5
a bc ad adc bcd
1
m
Sample Output 2 :
3
1
Explanation For Sample Input 2 :
For test case 1 :
We will print 3 because:
The longest possible string chain is “a” -> “ad” -> “adc”.
The length of the given chain is 3, hence the answer is 3.

For test case 2 :
We will print 1 because:
The longest possible string chain is “m”.
The length of the given chain is 1, hence the answer is 1.
*/



bool check(string &s1,string &s2){
    if(s1.size()!=s2.size()+1) return false;
    int first=0;
    int second=0;
    while(first<s1.size()){
    if(s1[first]==s2[second]){
        first++;
        second++;
    }
    else{
        first++;
    }
}
    if(first==s1.size() && second==s2.size()){
        return true;
    }
    return false;
}
bool cmp(string &s1,string &s2){
    return s1.size()<s2.size();
}

int longestStrChain(vector<string> &arr){
    sort(arr.begin(),arr.end(),cmp);
    int n=arr.size();
    int maxi=1;
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(arr[i],arr[j]) && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        if(maxi<dp[i]){
            maxi=dp[i];
       }      
    }
    return maxi;
}


