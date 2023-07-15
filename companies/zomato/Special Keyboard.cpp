#include <bits/stdc++.h>
  using namespace std;
  
  int dp[76];
  
  int getMax(int i){
    if(i<=0){
      return 0;
    }
    if(dp[i]!=-1){
      return dp[i];
    }
    int res=1+getMax(i-1);
    int left=i;
    left-=2;
    int count=1;
    while(left>0){
      count++;
      left--;
      res=max(res,count*getMax(left));
    }
    return dp[i]=res;
  }

  int main() {
    int n;
    cin>> n;
    memset(dp,-1,sizeof(dp));
    cout<<getMax(n)<<endl;
    return 0;
  }
