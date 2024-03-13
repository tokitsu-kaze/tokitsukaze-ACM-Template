struct Montgomery
{
	#define i64 int64_t
	#define u64 uint64_t
	#define u128 __uint128_t
	u64 mod,R;
	void set_mod(u64 p)
	{
		mod=R=p;
		for(int i=0;i<5;i++) R*=2-mod*R;
	}
    u64 mul_add(u64 a,u64 b,u64 c)
	{
	    u128 d=u128(a)*b;
		u64 e=c+mod+(d>>64);
		u64 f=u64(d)*R;
		u64 g=(u128(f)*mod)>>64;
	    return e-g;
	}
    u64 mul(u64 a,u64 b) {return mul_add(a,b,0);}
	#undef i64
	#undef u64
	#undef u128
};
// m.set_mod(p);
ll qpow(ll a,ll b,ll p)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=(__int128)res*a%p;
		a=(__int128)a*a%p;
		b>>=1;
	}
	return res;
}
bool miller_rabin(ll n,const initializer_list<ll>& as)
{
	int e=__builtin_ctzll(n-1);
	return all_of(as.begin(),as.end(),[&](ll it)
	{
		if(n<=it) return true;
		ll z=qpow(it,(n-1)>>e,n);  // it^(t*2^e)
		if(z==1||z==n-1) return true;
		for(int i=0;i<e-1;i++)
		{
			z=__int128(z)*z%n;
			if(z==1) return false;
			if(z==n-1) return true;
		}
		return false;
	});
}
bool is_prime(ll n)
{
	if(n<=2) return n==2;
	if(!(n&1)) return false;
	if(n<4759123141LL) return miller_rabin(n,{2,7,61});
	return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});
}
ll pollard_rho(ll n)
{
	Montgomery m;
	m.set_mod(n);
	if(!(n&1)) return 2;
	int i,j,k;
	ll q1,q2,g1,g2,w1,w2,x1,x2,y1,y2,z1,z2,g,c,x,z;
    constexpr ll c1=1;
    constexpr ll c2=2;
    constexpr ll M=512;
    w1=1,w2=2;
retry:
    z1=w1,z2=w2;
    for(i=M;;i<<=1)
	{
	    x1=z1+n,x2=z2+n;
	    for(j=0;j<i;j+=M)
		{
			y1=z1,y2=z2;
		    q1=1,q2=2;
		    for(k=0;k<M;k++)
			{
				z1=m.mul_add(z1,z1,c1);
				z2=m.mul_add(z2,z2,c2);
				q1=m.mul(q1,(x1-z1));
				q2=m.mul(q2,(x2-z2));
			}
		    g=__gcd((ll)m.mul(q1,q2),n);
		    if(g==1) continue;
		    if(g!=n) return g;
			g1=__gcd(q1,n);
		    g2=__gcd(q2,n);
		    if(g1!=1) c=c1,x=x1,z=y1,g=g1;
		    else c=c2,x=x2,z=y2,g=g2;
		    if(g==n)
			{
			    do{
				    z=m.mul_add(z,z,c);
				    g=__gcd(n,x-z);
				}while(g==1);
			}
		    if(g!=n) return g;
		    w1+=2,w2+=2;
		    goto retry;
		}
	}
}
void find_fac(ll n,vector<ll>& res)
{
	if(n<=1) return;
    if(is_prime(n)) {res.push_back(n); return;}
    ll p=pollard_rho(n);
    find_fac(p,res);
    find_fac(n/p,res);
}
vector<ll> factorize(ll n)
{
    vector<ll> res;
    find_fac(n,res);
    return res;
}
