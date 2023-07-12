// inbuilt data structure, look at import statements

#include <bits/stdc++.h>
  using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

  int main() {

    int t;
    cin>>t;
    while(t--){
      int n,nq;
      cin>>n>>nq;
      ordered_set s;
      for(int i=1;i<=n;i++){
        s.insert(i);
      }
      int type,x;
      for(int i=0;i<nq;i++){
        cin>>type>>x;
        auto it=s.find_by_order(x-1);
        if(type==1){
          s.erase(it);
        }else{
          cout<<*it<<endl;
        }
      }
    }

    return 0;

  }

