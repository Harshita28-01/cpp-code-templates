// DSU O(4*alpha) : is a complex mathematical expression but can be considered constant

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
