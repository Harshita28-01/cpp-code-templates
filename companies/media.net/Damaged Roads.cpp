#include <bits/stdc++.h>
  using namespace std;
  using ll=long long;
  
  int mod=1e9+7;
  
  int f(ll n,ll m,vector<int>&a,vector<int>&b){
    int res=0;
    int i=0,j=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(i<n-1 && j<m-1){
      if(a[i]<b[j]){
        res=(res+a[i]*(m-j))%mod;
        i++;
      }else{
        res=(res+b[j]*(n-i))%mod;
        j++;
      }
    }
    while(i<n-1){
      res=(res+a[i]*(m-j))%mod;
      i++;
    }
    while(j<m-1){
      res=(res+b[j]*(n-i))%mod;
      j++;
    }
    return res;
  }

  int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n-1),b(m-1);
    for(int i=0;i<n-1;i++){
      cin>>a[i];
    }
    for(int i=0;i<m-1;i++){
      cin>>b[i];
    }
    cout<<f(n,m,a,b)<<endl;
    return 0;

  }
