#include <bits/stdc++.h>
  using namespace std;
  using ll=long long;
  
  int mod=1e9+7;
  int N=1e5+1;
  set<int> primes;

  void getPrimes(){
    vector<int> v(N+1);
    iota(v.begin(),v.end(),0);
    for(int i=2;i*i<=N;i++){
      if(v[i]!=i){
        continue;
      }
      for(int j=i*i;j<=N;j+=i){
        v[j]=i;
      }
    }
    for(int i=2;i<=N;i++){
      if(v[i]==i){
        primes.insert(i);
      }
    }
  }
  

  int getNoOfGPs(int n,vector<int> &arr){
    ll res=0;
    map<pair<int,int>,int> um;
    unordered_map<int,int> cnt;
    // f-> a,s-> r
    for(int a:arr){
      cnt[a]++;
      for(int r:primes){
        if(r>a){
          break;
        }
        if(((a%r)==0)){
          um[{a,r}]=(um[{a,r}]+um[{a/r,r}]+cnt[a/r])%mod;
        }
      }
    }
    for(auto cur:um){
      res=(res+cur.second)%mod;
    }
    return (res)%mod;
  }
  

  int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    getPrimes();
    cout<<getNoOfGPs(n,arr)<<endl;
    return 0;

  }
