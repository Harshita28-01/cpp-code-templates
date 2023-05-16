struct seg_tree{
    vector<int> seg;
    int n;
    seg_tree(int _n): n(_n){
        seg.resize(4*n);
    }
    void update(int pos,int val,int l=0,int r=-1,int i=0){
        if(r==-1){
            r+=n;
        }
        if(l==r){
            seg[i]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=pos){
            update(pos,val,l,mid,2*i+1);
        }else{
            update(pos,val,mid+1,r,2*i+2);
        }
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    int query(int x,int y,int l=0,int r=-1,int i=0){
        if(r==-1){
            r+=n;
        }
        if(y<l || x>r){
            return 0;
        }
        if(l>=x && r<=y){
            return seg[i];
        }
        int mid=(l+r)>>1;
        return max(query(x,y,l,mid,2*i+1),query(x,y,mid+1,r,2*i+2));
    }
};
