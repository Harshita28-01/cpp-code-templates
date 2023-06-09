  void artiDFS(int cur,int prev,int &time,vector<int>adj[],
    vector<int> &time_in,vector<int> &low_time,vector<bool> &vis,vector<bool> &ans){
        vis[cur]=true;
        time_in[cur]=low_time[cur]=(time++);
        int children=0;
        for(int next:adj[cur]){
            if(next==prev){
                continue;
            }
            
            if(!vis[next]){
                artiDFS(next,cur,time,adj,time_in,low_time,vis,ans);
                low_time[cur]=min(low_time[cur],low_time[next]);
                if(prev!=-1 && low_time[next]>=time_in[cur]){
                    ans[cur]=true;
                }
                children++;
            }else{
                low_time[cur]=min(low_time[cur],time_in[next]);
            }
        }
        if(prev==-1 && children>1){
            ans[cur]=true;
        }
    }
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> time_in(v),low_time(v,1e9),res;
        vector<bool> vis(v),ans(v);
        int time=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                artiDFS(i,-1,time,adj,time_in,low_time,vis,ans);
            }
        }
        for(int i=0;i<v;i++){
            if(ans[i]){
                res.push_back(i);
            }
        }
        if(res.size()==0){
            return {-1};
        }
        return res;
    }
