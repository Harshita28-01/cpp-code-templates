bool bfs(int ind,int v, vector<int> adj[],vector<bool>&vis){
        queue<pair<int,int>> q;
        q.push({ind,-1});
        vis[ind]=true;
        while(q.size()){
            int cur=q.front().first,prev=q.front().second;
            q.pop();
            for(int next:adj[cur]){
                if(!vis[next]){
                    q.push({next,cur});
                    vis[next]=true;
                }else if(next!=prev){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int cur,int prev,vector<bool> &vis,vector<int> adj[]){
        vis[cur]=true;
        for(int next:adj[cur]){
            if(!vis[next]){
                if(dfs(next,cur,vis,adj)){
                    return true;
                }
            }else if(next!=prev){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v);
        for(int i=0;i<v;i++){
            // if(!vis[i] && bfs(i,v,adj,vis)){
            //     return true;
            // }
            if(!vis[i] && dfs(i,-1,vis,adj)){
                return true;
            }
        }
        return false;
    }


