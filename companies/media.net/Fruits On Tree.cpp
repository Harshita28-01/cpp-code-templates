// TODO:- Understand this!!!!
// This is copied code for reference

#include <bits/stdc++.h>
  using namespace std;
  long long dfs(long long src,long long par,vector<long long> adj[],vector<long long> &sum,vector<long long> &depth,vector<long long> &a,vector<long long> &c)
  {
    if(a[src]!=0)
    {
      depth[src]=0;
      sum[src]=a[src];
      return a[src];
    }
    long long maxi=0;
    for(auto x:adj[src])
    {
      if(x!=par)
      {
        long long temp=dfs(x,src,adj,sum,depth,a,c);
        sum[src]+=(temp-depth[x]);
        depth[src]=depth[x]+1;
        maxi=max(maxi,temp);
      }
    }
    return (maxi + min(c[src],sum[src]-(maxi-depth[src])));
  }
  int main() {

    long long n;
    cin>>n;
    vector<long long> a(n+1);
    vector<long long> c(n+1);
    
    for(long long i=0;i<n;i++)
    cin>>a[i+1];
    for(long long i=0;i<n;i++)
    cin>>c[i+1];
    
    vector<long long> adj[n+1];
    for(long long i=1;i<n;i++)
    {
      long long u,v;
      cin>>u>>v;
      
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<long long> sum(n+1,0);
    vector<long long> depth(n+1);
    cout<<dfs(1,0,adj,sum,depth,a,c);

    return 0;

  }
