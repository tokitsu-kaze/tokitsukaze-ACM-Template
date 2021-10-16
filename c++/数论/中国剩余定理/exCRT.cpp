namespace exCRT
{
	ll excrt(VL a,VL b)//res=a_i(mod b_i)
	{
	    ll x,y,k,g,c,p,res,bg;
	    assert(sz(a)==sz(b));
	    assert(sz(a)>0);
	    p=b[0];
		res=a[0];
	    for(int i=1;i<sz(a);i++)
	    {
	        c=(a[i]-res%b[i]+b[i])%b[i];
	        g=exgcd(p,b[i],x,y);
			bg=b[i]/g;
	        if(c%g!=0) return -1;
	        x=(x*(c/g))%bg;
	        res+=x*p;
	        p*=bg;
	        res=(res%p+p)%p;
	    }
	    return (res%p+p)%p;
	}
};
