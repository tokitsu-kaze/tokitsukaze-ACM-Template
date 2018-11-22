ll kth(ll n,ll m,ll k)
{
	if(m==1) return k;
	ll res=(m-1)%(n-k+1);
	for(ll i=n-k+2,stp=0;i<=n;i+=stp,res+=stp*m)
	{
		if(res+m>=i)
		{
			res=(res+m)%i;
			i++;
			stp=0;
		}
		else
		{
			stp=(i-res-2)/(m-1);
			if(i+stp>n)
			{
				res+=(n-(i-1))*m;
				break;
			}
		}
	}
	return res+1;
}
