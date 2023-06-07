// using priority_queue (not a safe implementation, use only to impress interviewer)
  vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v,1e9);
        auto comp=[&](int l,int r){
            return dist[l]>dist[r];
        };
        dist[s]=0;
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);
        pq.push(s);
        while(pq.size()){
            int cur=pq.top();
            pq.pop();
            for(vector<int>& next:adj[cur]){
                int nextNode=next[0],cost=next[1];
                if(dist[nextNode]>dist[cur]+cost){
                    dist[nextNode]=dist[cur]+cost;
                    pq.push(nextNode);
                }
            }
        }
        return dist;
    }

// priority_queue : safe

  vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v,1e9);
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        while(pq.size()){
            int cur=pq.top().second;
            pq.pop();
            for(vector<int>& next:adj[cur]){
                int nextNode=next[0],cost=next[1];
                if(dist[nextNode]>dist[cur]+cost){
                    dist[nextNode]=dist[cur]+cost;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        return dist;
    }

// using set (a bit more time optimal but bit less space optimal)

  vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        vector<int> dist(v,1e9);
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert({0,src});
        while(s.size()){
            int cur=(*s.begin()).second;
            s.erase(s.begin());
            for(vector<int> &next:adj[cur]){
                int nextNode=next[0],cost=next[1];
                if(dist[nextNode]>dist[cur]+cost){
                    if(s.count({dist[nextNode],nextNode})){
                        s.erase({dist[nextNode],nextNode});
                    }
                    dist[nextNode]=dist[cur]+cost;
                    s.insert({dist[nextNode],nextNode});
                }
            }
        }
        return dist;
    }
