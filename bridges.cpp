  void tarjan(int cur,int prev,int &time,vector<vector<int>> &adj,
                vector<int> &time_in,vector<int> &low_time,vector<vector<int>> &res){
        time_in[cur]=low_time[cur]=(time++);
        for(int next:adj[cur]){
            if(next==prev){
                continue;
            }
            if(time_in[next]>time_in[cur]){
                tarjan(next,cur,time,adj,time_in,low_time,res);
                if(time_in[cur]<low_time[next]){
                    res.push_back({cur,next});
                }
            }
            low_time[cur]=min(low_time[cur],low_time[next]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int time=0;
        vector<vector<int>> res;
        vector<vector<int>> adj(n);
        for(vector<int>&c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int> time_in(n,1e9),low_time(n,1e9);
        for(int i=0;i<n;i++){
            if(time_in[i]==1e9){
                tarjan(i,-1,time,adj,time_in,low_time,res);
            }
        }
        return res;
    }
