#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int binary[31];
const int mod = 1e9+7;
void findMaximumSum(
  const vector<int>& arr, int n)
{
  for (auto x : arr) {

    int idx = 0;

    while (x) {

      if (x & 1)
        binary[idx]++;
      x >>= 1;
      idx++;
    }
  }
    vector<int> temp;
    for (int i = 0; i < n; ++i) {

    int total = 0;

    for (int j = 0; j < 31; ++j) {

      if (binary[j] > 0) {
        total += pow(2, j);
        binary[j]--;
      }
    }

    temp.push_back(total*total);
  }
    sort(temp.begin(),temp.end());
    int x = temp.size()/2;
    for(int i=0;i<x;i++){
        ans=(ans%mod+temp[temp.size()-1-i]%mod)%mod;
    }
  cout << ans << endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  findMaximumSum(arr, n);

  return 0;
}
