// more runtime, but useful when multiple values are required, and factorial and inverse_factorial useful

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


// less runtime, optimal when only one time value required for each testcase

// memoisation:-
class Solution{
    int dp[1001][801], mod=1e9+7;
    int getncr(int n,int r){
        if(n<r){
            return 0;
        }
        if(n==r || r==0){
            return 1;
        }
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        return dp[n][r]=(getncr(n-1,r)+getncr(n-1,r-1))%mod;
    }
public:
    int nCr(int n, int r){
        memset(dp,-1,sizeof(dp));
        return getncr(n,r);
    }
};

// tabulation:- 
class Solution{
public:
    int nCr(int n, int r){
        if(n<r){
            return 0;
        }
        int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(r+1));
        // nC0=1
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        // nCn=1
        for(int i=0;i<=r;i++){
            dp[i][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i && j<=r;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        return dp[n][r];
    }
};
   
