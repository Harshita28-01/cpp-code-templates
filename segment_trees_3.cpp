struct seg_tree{
        int n;
        vector<int> seg;
        seg_tree(int n):n(n){
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
            if(pos>mid){
                update(pos,val,mid+1,r,2*i+2);
            }else{
                update(pos,val,l,mid,2*i+1);
            }
            seg[i]=seg[2*i+1]+seg[2*i+2];
        }
        int query(int x,int y,int l=0,int r=-1,int i=0){
            if(r==-1){
                r+=n;
            }
            if(y<l || x>r){
                return 0;
            }
            if(x<=l && r<=y){
                return seg[i];
            }
            int mid=(l+r)>>1;
            return query(x,y,l,mid,2*i+1)+query(x,y,mid+1,r,2*i+2);
        }
        
    };
