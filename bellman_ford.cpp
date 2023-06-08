  vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n,1e8);
        dist[src]=0;
        vector<int> res;
        for(int l=0;l<n;l++){
            for(vector<int> &e:edges){
                int u=e[0],v=e[1],c=e[2];
                if(dist[v]>dist[u]+c){
                    dist[v]=dist[u]+c;
                }
            }
            // to check for -ve cycles
            if(l==n-2){
                res=dist;
            }
        }
        if(res!=dist){
            return {-1};
        }
        return res;
    }
