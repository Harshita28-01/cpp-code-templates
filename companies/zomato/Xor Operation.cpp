#include <bits/stdc++.h>
  using namespace std;
  
  vector<vector<int>> prefixBits={vector<int>(31,0)};
  void pushBack(int x){
    prefixBits.push_back(prefixBits.back());
    for(int i=0;i<31;i++){
      if((1<<i) & x){
        prefixBits.back()[i]++;
      }
    }
  }
  
  long long query(int l,int r,int x){
    vector<int> cnt=prefixBits[r+1];
    long long res=0;
    for(int i=0;i<31;i++){
      cnt[i]-=prefixBits[l][i];
      if((1<<i) & x){
        cnt[i]=r-l+1-cnt[i];
      }
      res+=(long long)(1<<i)*cnt[i];
    }
    return res;
  }

  int main() {
    int n,nq;
    cin>>n>>nq;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
      pushBack(arr[i]);
    }
    int l,r,x;
    for(int i=0;i<nq;i++){
      cin>>l>>r>>x;
      l--,r--;
      cout<<query(l,r,x)<<endl;
    }

    return 0;

  }
