// Prim's algorithm- O(E logE) + O(E logE)

  int spanningTree(int v, vector<vector<int>> adj[])
    {
        int res=0;
        vector<bool> vis(v);
        // {cost of edge,{next node,parent node}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        while(pq.size()){
            int cur=pq.top().second.first,par=pq.top().second.second,cost=pq.top().first;
            pq.pop();
            if(vis[cur]){
                continue;
            }
            vis[cur]=true;
            res+=cost;
            // this edge is a part of MST
            for(vector<int> &nextEdge:adj[cur]){
                int next=nextEdge[0],edgeCost=nextEdge[1];
                if(vis[next]){
                    continue;
                }
                pq.push({edgeCost,{next,cur}});
            }
        }
        return res;
    }


// Kruskal's algorithm- O(E logE) + O(E)

class DSU{
    public:
    vector<int> parent,sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int getParent(int cur){
        if(cur==parent[cur]){
            return cur;
        }
        return parent[cur]=getParent(parent[cur]);
    }
    void setUnion(int u,int v){
        u=getParent(u);
        v=getParent(v);
        if(u==v){
            return;
        }
        if(sz[u]<sz[v]){
            parent[u]=v;
            sz[v]+=sz[u];
        }else{
            parent[v]=u;
            sz[u]+=sz[v];
        }
    }
    bool isUnion(int u,int v){
        return getParent(u)==getParent(v);
    }
};
class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(vector<int>& j:adj[i]){
                edges.push_back({j[1],j[0],i});
            }
        }
        int res=0;
        sort(edges.begin(),edges.end());
        DSU d(n);
        for(vector<int> &e:edges){
            int u=e[1],v=e[2],cost=e[0];
            if(!d.isUnion(u,v)){
                res+=cost;
                d.setUnion(u,v);
            }
        }
        return res;
    }
};

