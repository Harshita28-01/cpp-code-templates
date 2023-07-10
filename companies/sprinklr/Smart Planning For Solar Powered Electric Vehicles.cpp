#include <bits/stdc++.h>
  using namespace std;
  
  int getMoves(vector<int> &curr,vector<int> &des,int n){
    int res=0,i=0;
    while(i<n){
      if((curr[i]==-1 || des[i]==-1) && curr[i]!=des[i]){
        return -1;
      }
      if(curr[i]==-1){
        i++;
      }
      vector<int> a,b;
      unordered_map<int,int> um;
      while(i<n && curr[i]!=-1 && des[i]!=-1){
        if(curr[i]!=0){
          a.push_back(curr[i]);
          if(um.count(curr[i])){
            res+=abs(i-um[curr[i]]);
          }else{
            um[curr[i]]=i;
          }
        }
        if(des[i]!=0){
          b.push_back(des[i]);
          if(um.count(des[i])){
            res+=abs(i-um[des[i]]);
          }else{
            um[des[i]]=i;
          }
        }
        i++;
      }
      if(a!=b){
        return -1;
      }
    }
    return res;
  }

  int main() {

    int t;
    cin>> t;
    while(t--){
      int n;
      cin>>n;
      vector<int> curr(n);
      vector<int> des(n);
      for(int i=0;i<n;i++){
        cin>>curr[i];
      }
      for(int i=0;i<n;i++){
        cin>>des[i];
      }
      cout<<getMoves(curr,des,n)<<endl;
    }
    return 0;

  }
