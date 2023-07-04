#include <bits/stdc++.h>
  using namespace std;
  
  int mod=1e9+7;
  int dp[101][101][2];
  
  int getWays(int n,int m,bool prevWhite,int w,int y){
    if(n==0 && m==0){
      return 1;
    }
    if(n<0 || m<0){
      return 0;
    }
    if(dp[n][m][prevWhite]!=-1){
      return dp[n][m][prevWhite];
    }
    int res=0;
    if(prevWhite){
      for(int i=1;i<=min(m,y);i++){
        res=(res+getWays(n,m-i,false,w,y))%mod;
      }
    }else{
      for(int i=1;i<=min(n,w);i++){
        res=(res+getWays(n-i,m,true,w,y))%mod;
      }
    }
    return dp[n][m][prevWhite]=res;
  }

  int main() {
    int n,m,w,y;
    cin>>n>>m>>w>>y;
    memset(dp,-1,sizeof(dp));
    cout<<(getWays(n,m,false,w,y)+getWays(n,m,true,w,y))%mod<<endl;
    return 0;
  }
