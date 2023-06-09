  // Other functions, scroll for main "kosaraju" function
  // TC- O(V+E) + O(V+E) + O(V+E)
  // SC- O(V) + O(V) + O(V+E)
  void finishtime(int cur,vector<bool> &vis,stack<int> &s,vector<vector<int>>& adj){
        vis[cur]=true;
        for(int next:adj[cur]){
            if(!vis[next]){
                finishtime(next,vis,s,adj);
            }
        }
        s.push(cur);
    }
    void dfs(int cur,vector<bool> &vis,vector<vector<int>>& adj){
        vis[cur]=true;
        for(int next:adj[cur]){
            if(!vis[next]){
                dfs(next,vis,adj);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        // step 1- sort in order of finish time
        stack<int> s;
        vector<bool> vis(v);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                finishtime(i,vis,s,adj);
            }
        }
        // step 2- reverse the graph
        vector<vector<int>> adjr(v);
        for(int i=0;i<v;i++){
            for(int j:adj[i]){
                adjr[j].push_back(i);
            }
        }
        // step 3- do a DFS
        int res=0;
        vis.assign(v,false);
        while(s.size()){
            int cur=s.top();
            s.pop();
            if(!vis[cur]){
                res++;
                dfs(cur,vis,adjr);
            }
        }
        return res;
    }
