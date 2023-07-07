#include <bits/stdc++.h>
  using namespace std;
  
  int getMaxFreq(vector<int>&arr,long long x,int n){
    if(n==0){
      return 0;
    }
    int j=0;
    for(int i=1;i<n;i++){
      x-=(arr[i]-arr[i-1])*(i-j);
      if(x<0){
        x+=arr[i]-arr[j];
        j++;
      }
    }
    return n-j;
  }

  int main() {

    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<getMaxFreq(arr,x,n)<<endl;
    return 0;

  }
