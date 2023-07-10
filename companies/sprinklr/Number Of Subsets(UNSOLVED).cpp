// approach 1

#include <bits/stdc++.h>
  using namespace std;
  using ll=long long;
  
  ll mod=1e9+7;
  
  ll getTotalSubsets(int n){
    int res=1;
    for(int i=0;i<n;i++){
      res=(res<<1)%mod;
    }
    return res;
  }
  
  int solve(vector<int>& l, int k) {
    int n = l.size();
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= l[i]; --j) {
            dp[j] = (dp[j]+dp[j - l[i]])%mod;
        }
    }
    ll s=0;
    for(int d:dp){
      s=(s+d)%mod;
    }
    s=(s<<1)%mod;
    return (getTotalSubsets(n) - s + mod)%mod;
}
  
  int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    ll s=0;
    for(int i=0;i<n;i++){
      s+=arr[i];
    }
    if(s<2*(k+1)){
      cout<<0<<endl;
    }else{
      cout<<solve(arr,k)<<endl;
    }
    
    return 0;

  }

// approach 2

#include <bits/stdc++.h>
  using namespace std;
  using ll=long long;
  
  int dp[1001][1001];
  ll mod=1e9+7;
  
  ll getTotalSubsets(int n){
    int res=1;
    for(int i=0;i<n;i++){
      res=(res<<1)%mod;
    }
    return res;
  }
  
  ll f(int i,int j,vector<int> &arr,int n,int k){
    if(i==n){
      return 1;
    }
    if(dp[i][j]!=-1){
      return dp[i][j];
    }
    ll res=f(i+1,j,arr,n,k);
    if(j+arr[i]<=k){
      res=(res+f(i+1,j+arr[i],arr,n,k))%mod;
    }
    return dp[i][j]=res;
  }

  int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    ll s=0;
    for(int i=0;i<n;i++){
      s+=arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(s<=2*k+1){
      cout<<0<<endl;
    }else{
      cout<<(getTotalSubsets(n)-2*f(0,0,arr,n,k)+2*mod)%mod<<endl;
    }
    return 0;

  }
