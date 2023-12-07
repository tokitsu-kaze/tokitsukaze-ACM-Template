ll cal(ll a0,ll q,ll n,ll p)
{
	int i;
	ll tmp[33],sum[33],res,now;
	tmp[0]=0;
	tmp[1]=q;
	for(i=2;i<=30;i++) tmp[i]=tmp[i-1]*tmp[i-1]%p;
	sum[0]=1;
	for(i=1;i<=30;i++) sum[i]=sum[i-1]*(1+tmp[i])%p;
	res=0;
	now=1;
	for(i=30;~i;i--)
	{
		if((n>>i)&1)
		{
			res=(res+now*sum[i])%p;
			now=(now*tmp[i+1])%p;
		}
	}
	return a0*res%p;
}
