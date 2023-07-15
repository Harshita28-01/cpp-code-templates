#include <bits/stdc++.h>
  using namespace std;
  using ll=long long;
  
  ll mod=1e9+7;
  
  int dpSum[61][61][61];
  int dpCount[61][61][61];
  
  pair<int,int> findSum(int x,int y,int z){
    if(dpSum[x][y][z]!=-1){
      return {dpSum[x][y][z],dpCount[x][y][z]};
    }
    ll resSum=0,resCount=0;
    if(x!=0){
      pair<int,int> cur=findSum(x-1,y,z);
      ll curSum=cur.first,curCount=cur.second;
      resSum=(resSum+ curSum*10+curCount*4 + 4)%mod;
      resCount=(resCount+curCount+1)%mod;
    }
    if(y!=0){
      pair<int,int> cur=findSum(x,y-1,z);
      ll curSum=cur.first,curCount=cur.second;
      resSum=(resSum+ curSum*10+curCount*5 + 5)%mod;
      resCount=(resCount+curCount+1)%mod;
    }
    if(z!=0){
      pair<int,int> cur=findSum(x,y,z-1);
      ll curSum=cur.first,curCount=cur.second;
      resSum=(resSum+ curSum*10+curCount*6 + 6)%mod;
      resCount=(resCount+curCount+1)%mod;
    }
    return {dpSum[x][y][z]=resSum,dpCount[x][y][z]=resCount};
  }

  int main() {
    memset(dpSum,-1,sizeof(dpSum));
    int x,y,z;
    cin>>x>>y>>z;
    cout<<findSum(x,y,z).first<<endl;
    return 0;

  }
