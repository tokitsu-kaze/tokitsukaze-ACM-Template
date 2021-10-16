struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed%p;
			Hash[i]=(Hash[i-1]*seed+s[i])%p;//may need change
		}
	}
	ll get(int l,int r)
	{
		return ((Hash[r]-Hash[l-1]*tmp[r-l+1])%p+p)%p;
	}
};
