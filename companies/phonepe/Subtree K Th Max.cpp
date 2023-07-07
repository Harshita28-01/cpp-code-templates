#include <bits/stdc++.h>
  using namespace std;
  
  int rankOf[100001][40];
  
  void setRanks(int cur,int next){
    for(int i=0;i<20;i++){
      rankOf[cur][i+20]=rankOf[next][i];
    }
    sort(rankOf[cur],rankOf[cur]+40,greater<int>());
  }
  
  void fillRank(int cur,int prev,vector<int> adj[],vector<int> &vals){
    rankOf[cur][0]=vals[cur];
    for(int next:adj[cur]){
      if(next==prev){
        continue;
      }
      fillRank(next,cur,adj,vals);
      setRanks(cur,next);
    }
  }
  int main() {
    int n,u,v,nq;
    cin>>n>>nq;
    vector<int> vals(n);
    for(int i=0;i<n;i++){
      cin>>vals[i];
    }
    vector<int> adj[n];
    for(int i=0;i<n-1;i++){
      cin>>u>>v;
      u--,v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(rankOf,-1,sizeof(rankOf));
    fillRank(0,-1,adj,vals);
    for(int i=0;i<nq;i++){
      cin>>u>>v;
      u--,v--;
      cout<<rankOf[u][v]<<endl;
    }
    return 0;
  }
