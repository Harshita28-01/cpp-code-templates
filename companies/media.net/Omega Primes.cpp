#include <bits/stdc++.h>
  using namespace std;
  
  int primes[10]={2,3,5,7,11,13,17,19,23,29};
  
  int getMask(int num){
    int res=0;
    for(int i=0;i<10;i++){
      if((num%primes[i])==0){
        res|=(1<<i);
      }
    }
    return res;
  }
  
  int dp[20000][1024];
  int mod=1e9+7;
  
  int f(int i,int mask,int n,vector<int> &arr){
    if(i==n){
      return (mask!=0);
    }
    if(dp[i][mask]!=-1){
      return dp[i][mask];
    }
    int res=f(i+1,mask,n,arr);
    if((mask&arr[i])==0){
      res=(res+f(i+1,mask|arr[i],n,arr))%mod;
    }
    return dp[i][mask]=res;
  }

  int main() {
    int n;
    cin>>n;
    vector<int> arr;
    int ele;
    for(int i=0;i<n;i++){
      cin>>ele;
      bool take=true;
      for(int j=0;j<10 && primes[j]*primes[j]<=ele;j++){
        if(ele%(primes[j]*primes[j])==0){
          take=false;
          break;
        }
      }
      if(take){
        arr.push_back(getMask(ele));
      }
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(0,0,arr.size(),arr)<<endl;
    return 0;

  }
