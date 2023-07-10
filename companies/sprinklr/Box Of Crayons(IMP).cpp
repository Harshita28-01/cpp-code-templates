#include <bits/stdc++.h>
  using namespace std;
  
  int dp[61][61][61];
  
  int square(int n){
    return n*n;
  }
  
  // dp[l][r][k]
  // range from l to r
  // k occurances of s[l] before [l:r]
  // 2 options- either cash in the available frequency, or find another character similar to s[l]
  
  
  int f(int l,int r,int k,string &s){
    if(l>r){
      return 0;
    }
    if(dp[l][r][k]!=-1){
      return dp[l][r][k];
    }
    int res=square(k+1)+f(l+1,r,0,s);
    for(int i=l+1;i<=r;i++){
      if(s[l]==s[i]){
        res=max(res,f(l+1,i-1,0,s)+f(i,r,k+1,s));
      }
    }
    return dp[l][r][k]=res;
  }
  
  

  int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<f(0,n-1,0,s)<<endl;
    return 0;

  }
