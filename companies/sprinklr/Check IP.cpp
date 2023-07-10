#include <bits/stdc++.h>
  using namespace std;
  
  bool isNum(char c){
    return c>='0' && c<='9';
  }
  
  bool isAlphaNum(char c){
    return isNum(c) || (c>='a' && c<='f' ) || (c>='A' && c<='F' );
  }
  
  bool ipv6(string s){
    s.push_back(':');
    int len=0;
    int blocks=0;
    for(char c:s){
      if(isAlphaNum(c)){
        len++;
      }else if(c==':'){
        if(len==0 || len>4){
          return false;
        }
        len=0;
        blocks++;
      }else{
        return false;
      }
    }
    return blocks==8;
  }
  
  bool ipv4(string s){
    s.push_back('.');
    bool beg=true;
    int num=0;
    int blocks=0;
    for(char c:s){
      if(isNum(c)){
        if(!beg && c>='1' && c<='9' && (num==0)){
          return false;
        }
        beg=false;
        num=num*10+c-'0';
      }else if(c=='.'){
        if(beg || num>255){
          return false;
        }
        beg=true;
        blocks++;
        num=0;
      }else{
        return false;
      }
    }
    return blocks==4;
  }

  int main() {

    string s;
    cin>> s;
    if(ipv4(s)){
      cout<<"IPv4"<<endl;
    }else if(ipv6(s)){
      cout<<"IPv6"<<endl;
    }else{
      cout<<"Invalid"<<endl;
    }
    return 0;

  }
