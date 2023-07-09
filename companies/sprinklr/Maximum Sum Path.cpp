#include <bits/stdc++.h>
  using namespace std;
  
  int getMaxi(vector<int> &arr){
    if(arr.size()==0){
      return 0;
    }
    vector<int> left,right;
    int n=arr.size(),cur=arr[0];
    for(int i=1;i<n;i++){
      if(arr[i]<cur){
        left.push_back(arr[i]);
      }else{
        right.push_back(arr[i]);
      }
    }
    return max(getMaxi(left),getMaxi(right))+cur;
  }

  int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cout<<getMaxi(arr)<<endl;

    return 0;

  }
