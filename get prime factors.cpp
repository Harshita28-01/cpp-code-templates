    vector<int> v;
    void getSieve(int n){
        v.resize(n);
        iota(v.begin(),v.end(),0);
        for(int i=2;i*i<n;i++){
            if(i!=v[i]){
                continue;
            }
            for(int j=i*i;j<n;j+=i){
                v[j]=i;
            }
        }
    }
    vector<int> getPrimes(int n){
        vector<int> res;
        while(n!=1){
            int f=v[n];
            while((n%f)==0){
                n/=f;
            }
            res.push_back(f);
        }
        return res;
    }


