    const int M=1e9+7;
    vector<int> fact,inv_fact;
    ll fast_power(ll a,ll b){
        ll res=1;
        while(b){
            if(b & 1)res=(res * a)%M;
            a=(a*a)%M;
            b/=2;
        }
        return res;
    }
    void init(){
        int n=1e5+1;
        fact.resize(n);
        inv_fact.resize(n);
        fact[0]=1;
        for(ll i=1;i<n;i++){
            fact[i]=(fact[i-1]*i)%M;
            inv_fact[i]=fast_power(fact[i],M-2);
        }
    }
    int calc(vector<int> &f){
        int n=accumulate(f.begin(),f.end(),0);
        ll res=fact[n];
        for(int i:f){
            if(i==0)continue;
            res=(res * inv_fact[i])%M;
        }
        return res;
    }
