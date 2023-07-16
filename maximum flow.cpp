// Change the following:
// 1. source and sink
// 2. undirected or directed config (below- undirected)
// The code runs in O(max_flow * E) time and O(V+E) space

class Solution
{
    bool findAugmentingPath(int source,int sink,vector<vector<int>> &adj,int n,vector<int> &parent){
        vector<bool> vis(n);
        queue<int> q;
        q.push(source);
        vis[source]=true;
        parent[source]=-1;
        while(q.size()){
            int cur=q.front();
            q.pop();
            for(int next=0;next<n;next++){
                if(adj[cur][next]==0 || vis[next]){
                    continue;
                }
                parent[next]=cur;
                if(next==sink){
                    return true;
                }
                q.push(next);
                vis[next]=true;
            }
        }
        return false;
    }
public:
    int findMaxFlow(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<int>> adj(n,vector<int> (n));
        for(vector<int> e:edges){
            int u=e[0]-1,v=e[1]-1,val=e[2];
            adj[u][v]+=val;
            adj[v][u]+=val;
        }
        int flow=0;
        vector<int> parent(n,-1);
        int source=0,sink=n-1;
        while(findAugmentingPath(source,sink,adj,n,parent)){
            int cur=sink,bottleneck=1e9;
            while(cur!=source){
                int prev=parent[cur];
                bottleneck=min(bottleneck,adj[prev][cur]);
                cur=prev;
            }
            cur=sink;
            while(cur!=source){
                int prev=parent[cur];
                adj[prev][cur]-=bottleneck;
                adj[cur][prev]+=bottleneck;
                cur=prev;
            }
            flow+=bottleneck;
        }
        return flow;
    }
};
