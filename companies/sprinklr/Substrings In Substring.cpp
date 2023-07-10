#include <bits/stdc++.h>
  using namespace std;
  
  void getPrefix(string &s,vector<vector<int>>&pre){
    for(char c:s){
      pre.push_back(pre.back());
      pre.back()[c-'a']++;
    }
  }
  
  int getSubarrays(vector<int>&a,vector<int>&b){
    int res=0;
    for(int i=0;i<26;i++){
      int f=b[i]-a[i];
      res+=f*(f+1)/2;
    }
    return res;
  }
  

  int main() {
    int t;
    cin>>t;
    while(t--){
      int n,nq;
      string s;
      cin>>n>>nq;
      cin>>s;
      int a,b;
      vector<vector<int>>pre;
      pre.push_back(vector<int>(26));
      getPrefix(s,pre);
      for(int i=0;i<nq;i++){
        cin>>a>>b;
        a--,b;
        cout<<getSubarrays(pre[a],pre[b])<<endl;
      }
    }

    return 0;

  }
