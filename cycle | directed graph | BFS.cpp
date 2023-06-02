// make two arrays vis and path
  bool dfs(int cur,vector<int> adj[],vector<bool> &vis,vector<bool> &path){
        vis[cur]=true;
        path[cur]=true;
        for(int next:adj[cur]){
            if(!vis[next]){
                if(dfs(next,adj,vis,path)){
                    return true;
                }
            }else if(path[next]){
                return true;
            }
        }
        path[cur]=false;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> vis(v),path(v);
        for(int i=0;i<v;i++){
            if(!vis[i] && dfs(i,adj,vis,path)){
                return true;
            }
        }
        return false;
    }
