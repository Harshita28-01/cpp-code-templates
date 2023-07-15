#include <bits/stdc++.h>
  using namespace std;
  
  int adj[501][501];
  
  int oppositeGroup(int x){
    return (!(x-1))+1;
  }
  
  bool isBipartiteDFS(int cur,int group,vector<vector<int>> &adj,vector<int> &vis){
    vis[cur]=group;
    int nextGroup=oppositeGroup(group);
    for(int next:adj[cur]){
      if(!vis[next]){
        if(!isBipartiteDFS(next,nextGroup,adj,vis)){
          return false;
        }
      }else if(vis[next]!=nextGroup){
        return false;
      }
    }
    return true;
  }
  
  bool isBipartite(int n,vector<vector<int>> &edges){
    vector<vector<int>> adj(n);
    for(vector<int> edge:edges){
      int u=edge[0],v=edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(n);
    for(int i=0;i<n;i++){
      if(adj[i].size() && vis[i]==0 && !isBipartiteDFS(i,1,adj,vis)){
        return false;
      }
    }
    int one=0,two=0;
    for(int v:vis){
      if(v==1){
        one++;
      }else if(v==2){
        two++;
      }
    }
    int other=n-one-two;
    while(one<2){
      other--;
      one++;
    }
    while(two<2){
      other--;
      two++;
    }
    return other>=0;
  }
  
  bool isPossible(int x,int n){
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(adj[i][j]<x){
          edges.push_back({i,j});
        }
      }
    }
    return isBipartite(n,edges);
  }
  
  int getMaxMin(int n){
    int l=1,r=1e9,mid;
    while(l<=r){
      mid=(l+r)>>1;
      if(isPossible(mid,n)){
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
    return r;
  }
  

  int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>adj[i][j];
      }
    }
    cout<<getMaxMin(n)<<endl;
    return 0;

  }
