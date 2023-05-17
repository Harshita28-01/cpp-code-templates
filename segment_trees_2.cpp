struct seg_trees{
    vector<vector<int>> seg;
    int n;
    seg_trees(int _n):n(_n){
        seg.resize(4*n);
        for(int i=0;i<4*n;i++){
            seg[i].resize(26);
        }
    }
    vector<int> getCharCount(vector<int> v1,vector<int> v2){
        vector<int> v(26);
        for(int j=0;j<26;j++){
            v[j]=v1[j]+v2[j];
        }
        return v;
    }
    void update(int pos,int ch,int l=0,int r=-1,int i=0){
        if(r==-1){
            r+=n;
        }
        if(l==r){
            seg[i].assign(26,0);
            seg[i][ch]++;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            update(pos,ch,l,mid,2*i+1);
        }else{
            update(pos,ch,mid+1,r,2*i+2);
        }
        seg[i]=getCharCount(seg[2*i+1],seg[2*i+2]);
    }
    vector<int> query(int x,int y,int l=0,int r=-1,int i=0){
        if(r==-1){
            r+=n;
        }
        if(r<x || l>y){
            return vector<int>(26);
        }
        if(l>=x && r<=y){
            return seg[i];
        }
        int mid=(l+r)>>1;
        return getCharCount(query(x,y,l,mid,2*i+1),query(x,y,mid+1,r,2*i+2));
    }
};
