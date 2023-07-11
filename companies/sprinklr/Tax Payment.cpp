#include <bits/stdc++.h>
  using namespace std;
  
  class seg_tree{
    public:
    int _n;
    vector<int> seg;
    seg_tree(int n):seg(4*n),_n(n){}
    void update(int idx,int val,int l=0,int r=-1,int i=0){
      if(r==-1){
        r+=_n;
      }
      if(l==r){
        seg[i]=val;
        return;
      }
      int mid=(l+r)/2;
      if(idx<=mid){
        update(idx,val,l,mid,2*i+1);
      }else{
        update(idx,val,mid+1,r,2*i+2);
      }
      seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int query(int x,int y,int l=0,int r=-1,int i=0){
      if(r==-1){
        r+=_n;
      }
      if(r<x || l>y){
        return 0;
      }
      if(l>=x && r<=y){
        return seg[i];
      }
      int mid=(l+r)/2;
      return query(x,y,l,mid,2*i+1)+query(x,y,mid+1,r,2*i+2);
    }
  };
  
  vector<int> getRes(vector<pair<int,int>> &arr,vector<vector<int>> queries,int nq,int n){
    vector<int> res(nq);
    seg_tree tree(n);
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    sort(queries.begin(),queries.end(),greater<vector<int>>());
    int i=0;
    for(vector<int> q:queries){
      int x=q[0],l=q[1],r=q[2],idx=q[3];
      while(i!=n && arr[i].first>x){
        tree.update(arr[i].second,1);
        i++;
      }
      res[idx]=tree.query(l,r);
    }
    return res;
  }

  int main() {
    int n,nq;
    cin>>n>>nq;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i].first;
      arr[i].second=i;
    }
    int l,r,x;
    vector<vector<int>> queries;
    for(int i=0;i<nq;i++){
      cin>>l>>r>>x;
      l--,r--;
      queries.push_back({x,l,r,i});
    }
    vector<int> res=getRes(arr,queries,nq,n);
    for(int q:res){
      cout<<q<<endl;
    }
    return 0;

  }
