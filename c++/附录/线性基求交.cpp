LBasis intersection(const LBasis &a, const LBasis &b){
    LBasis ans, c = b, d = b;
    ans.init();
    for (int i = 0; i <= 32; i++){
        ll x = a.d[i];
        if(!x)continue;
        int j = i;
        ll T = 0;
        for(; j >= 0; --j){
            if((x >> j) & 1)
                if(c.d[j]) {x ^= c.d[j]; T ^= d.d[j];}
                else break;
        }
        if(!x) ans.d[i] = T;
        else {c.d[j] = x; d.d[j] = T;}
    }
    return ans;
}