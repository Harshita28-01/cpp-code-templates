#include <bits/stdc++.h>
  using namespace std;
  
  int getMax(vector<int> &freq){
    for(int i=25;i>=0;i--){
      if(freq[i]){
        return i;
      }
    }
    return 0;
  }
  
  string getMaxString(string &s,int n,int k){
    string res;
    vector<int> freq(26);
    for(char c:s){
      freq[c-'a']++;
    }
    while(freq[getMax(freq)]){
      int c=getMax(freq),f=freq[c];
      freq[c]=0;
      while(f>k){
        for(int i=0;i<k;i++){
          res.push_back(c+'a');
        }
        f-=k;
        int nextC=getMax(freq);
        if(freq[nextC]==0){
          return res;
        }
        res.push_back(nextC+'a');
        freq[nextC]--;
      }
      for(int i=0;i<f;i++){
        res.push_back(c+'a');
      }
    }
    return res;
  }

  int main() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    cout<<getMaxString(s,n,k);
    return 0;
  }
