#include <bits/stdc++.h>
  using namespace std;
  
  class Coordinate{
    public:
    int x,y,k;
    Coordinate(int x,int y,int k):x(x),y(y),k(k){}
  };
  
  int dir[5]={0,1,0,-1,0};
  
  int vis[40][40];
  int mat[40][40];
  
  int get(int n,int m,int k){
    if(n==1 && m==1){
      if(mat[0][0]==1 && k==0){
        return -1;
      }
      return 0;
    }
    int level=0;
    queue<Coordinate> q;
    q.push(Coordinate(0,0,k));
    vis[0][0]=k;
    // cout<<k<<'|';
    while(q.size()){
      level++;
      int nq=q.size();
      for(int i=0;i<nq;i++){
        Coordinate cur=q.front();
        // cout<<"flag:"<<cur.x<<' '<<cur.y<<' '<<vis[cur.x][cur.y]<<'|';
        int curk=vis[cur.x][cur.y];
        q.pop();
        for(int j=0;j<4;j++){
          int x=cur.x+dir[j],y=cur.y+dir[j+1];
          if(x<0 || y<0 || x==n || y==m ){
            continue;
          }
          if(x==n-1 && y==m-1){
            // cout<<(curk)<<endl;
            return level;
          }
          int nextK=curk-mat[x][y];
          // cout<<x<<' '<<y<<' '<<vis[x][y]<<'|';
          // cout<<vis[x][y]<<'|';
          if(nextK<0 || vis[x][y]<= nextK){
            continue;
          }
          q.push(Coordinate(x,y,nextK));
          vis[x][y]=nextK;
        }
      }
    }
    return -1;
  }

  int main() {
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    for(int i=0;i<n;i++){
      cin>>s;
      for(int j=0;j<m;j++){
        mat[i][j]=s[j]-'0';
      }
    }
    memset(vis,1000000,sizeof(vis));
    cout<<get(n,m,k)<<endl;
    return 0;
  }
