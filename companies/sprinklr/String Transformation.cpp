#include <bits/stdc++.h>
  using namespace std;
  
  bool isPossible(string &s,string &t){
    if(s.size()!=t.size()){
      return false;
    }
    vector<int> v(26,-1);
    int n=s.size();
    for(int i=0;i<n;i++){
      int a=s[i],b=t[i];
      if(v[a-'a']==-1){
        v[a-'a']=b-'a';
      }else if(v[a-'a']!=b-'a'){
        return false;
      }
    }
    return true;
  }

  int main() {

    string s,t;
    cin>>s>>t;
    cout<<(isPossible(s,t)?"YES":"NO")<<endl;
    return 0;

  }
