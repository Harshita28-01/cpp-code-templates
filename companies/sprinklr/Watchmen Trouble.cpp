#include <bits/stdc++.h>
  using namespace std;
  
  bool assignNextJob(int i,vector<vector<int>>&g,vector<int> &pointer,vector<int>&appNo,int n){
        for(int p=0;p<n;p++){
            if(g[i][p] && !pointer[p]){
                pointer[p]=true;
                if(appNo[p]==-1 || assignNextJob(appNo[p],g,pointer,appNo,n)){
                    appNo[p]=i;
                    return true;
                }
            }
        }
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&g){
	    int m=g.size(),n=g[0].size();
	    vector<int> appNo(n,-1);
	    int res=0;
	    for(int i=0;i<m;i++){
	        vector<int> pointer(n);
	        if(assignNextJob(i,g,pointer,appNo,n)){
	            res++;
	        }
	    }
	    return res;
	}


  int main() {
    int n,m,p;
    cin>>n>>m>>p;
    int a,b;
    vector<vector<int>> adj(n,vector<int>(m));
    for(int i=0;i<p;i++){
      cin>>a>>b;
      a--,b--;
      adj[a][b]=true;
    }
    cout<<maximumMatch(adj)<<endl;
    return 0;

  }
