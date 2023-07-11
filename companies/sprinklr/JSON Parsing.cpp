#include <bits/stdc++.h>
  using namespace std;
  
  class Object{
    public:
    string s;
    unordered_map<string,Object*> um;
    Object(){}
    Object(string value){
      s=value;
    }
  };
  
  
  Object* traverse(int &i,string &s){
    if(i>=s.size()){
      return NULL;
    }
    Object* root=new Object;
    while(i<s.size() && s[i]=='"'){
      i++;
      string key;
      while(s[i]!='"'){
        key.push_back(s[i]);
        i++;
      }
      i++;
      i++;
      if(s[i]=='"'){
        string value;
        i++;
        while(s[i]!='"'){
          value.push_back(s[i]);
          i++;
        }
        root->um[key]=new Object(value);
        i++;
        i++;
      }else{
        i++;
        root->um[key]=traverse(i,s);
        i++;
      }
    }
    return root;
  }
  
  string processQuery(Object *root,int &i,string &query){
    if(i>=query.size()){
      return root->s;
    }
    string cur;
    while(i<query.size() && query[i]!='.'){
      cur.push_back(query[i]);
      i++;
    }
    i++;
    return processQuery(root->um[cur],i,query);
  }

  int main() {
    string s;
    cin>>s;
    int nq;
    cin>>nq;
    int i=0;
    Object* root=traverse(i,s);
    string query;
    for(int j=0;j<nq;j++){
      i=0;
      cin>>query;
      cout<<processQuery(root,i,query)<<endl;
    }
    return 0;

  }
