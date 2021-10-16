//O(log^2)
struct Tonelli_Shanks
{
	ll mul2(ll a,ll b,ll p)
	{
		ll res=0;
		a%=p;
		while(b)
		{
			if(b&1)
			{
				res+=a;
				if(res>=p) res-=p;
			}
			a+=a;
			if(a>=p) a-=p;
			b>>=1;
		}
		return res;
	}
	ll pow2(ll a,ll b,ll p)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=mul2(res,a,p);
			a=mul2(a,a,p);
			b>>=1;
		}
		return res;
	}
	ll sqrt(ll n,ll p)
	{
	    if(p==2) return (n&1)?1:-1;
	    if(pow2(n,p>>1,p)!=1) return -1;
	    if(p&2) return pow2(n,(p+1)>>2,p);
	    ll q,z,c,r,t,tmp,s,i,m;
	    s=__builtin_ctzll(p^1);
	    q=p>>s;
		z=2;
	    for(;pow2(z,p>>1,p)==1;z++);
	    c=pow2(z,q,p);
		r=pow2(n,(q+1)>>1,p);
		t=pow2(n,q,p);
	    for(m=s;t!=1;)
		{
	        for(i=0,tmp=t;tmp!=1;i++) tmp=tmp*tmp%p;
	        for(;i<--m;) c=c*c%p;
	        r=r*c%p;
	        c=c*c%p;
	        t=t*c%p;
	    }
	    return r;
	}
}ts;
