using ll=long long;
class Factorial{
    vector<int> fact;
    vector<int> inv_fact;
    ll mod;
    ll fast_power(ll a,ll b){
        ll res=1;
        while(b){
            if(b&1){
                res=(res*a)%mod;
                b--;
            }else{
                a=(a*a)%mod;
                b/=2;
            }
        }
        return res;
    }
    public:
    Factorial(int n):fact(n),inv_fact(n),mod(1e9+7){
        fact[0]=inv_fact[0]=1;
        for(ll i=1;i<n;i++){
            fact[i]=(i*fact[i-1])%mod;
            inv_fact[i]=fast_power(fact[i],mod-2);
        }
    }
    int getFact(int i){
        return fact[i];
    }
    int getInv(int i){
        return inv_fact[i];
    }
    ll ncr(int n,int r){
        return ((((ll)fact[n]*inv_fact[n-r])%mod)*inv_fact[r])%mod;
    }
};
