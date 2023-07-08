#include <bits/stdc++.h>
  using namespace std;
  
using ll=long long;
  
  
  ll getMaxi(vector<int> &a,vector<int>&b,int n){
    vector<int> c(n);
    ll asum=0,bsum=0;
    for(int i=0;i<n;i++){
      c[i]=a[i]-b[i];
      asum+=a[i];
      bsum+=b[i];
    }
    ll cur1=0,cur2=0,rMax1=0,rMax2=0;
    for(int i=0;i<n;i++){
      cur1+=c[i];
      if(cur1<0){
        cur1=0;
      }
      cur2-=c[i];
      if(cur2<0){
        cur2=0;
      }
      rMax1=max(rMax1,cur1);
      rMax2=max(rMax2,cur2);
    }
    return max(bsum+rMax1,asum+rMax2);
  }

  int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> a(n),b(n);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      for(int i=0;i<n;i++){
        cin>>b[i];
      }
      cout<<getMaxi(a,b,n)<<endl;
    }
    
    return 0;

  }
