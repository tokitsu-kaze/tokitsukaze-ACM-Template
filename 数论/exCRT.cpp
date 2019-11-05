ll a[111],b[111];
ll excrt(int n)//res=a_i(mod b_i)
{
    ll x,y,k,g,c,p,res,bg;
    p=b[1];
	res=a[1];
    for(int i=2;i<=n;i++)
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
