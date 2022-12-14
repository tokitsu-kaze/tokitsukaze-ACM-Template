VI LIS(VI a)
{
	int i,pos,len,mx,n;
	n=sz(a);
	VI b(n),tmp(n),res;
	for(i=0;i<n;i++)
	{
		//LIS: INF
		//LDS: -INF
		b[i]=INF;
	}
	for(i=0;i<n;i++)
	{
		//    strict: lower_bound
		//not strict: upper_bound
		pos=lower_bound(all(b),a[i])-b.begin();
		b[pos]=a[i];
		tmp[i]=pos;
	}
	len=lower_bound(all(b),INF)-b.begin();
	mx=INF;
	for(i=n-1;~i;i--)
	{
		if(!len) break;
		//    strict LIS: >
		//not strict LIS: >=
		//    strict LDS: <
		//not strict LDS: <=
		if(tmp[i]+1==len&&mx>a[i])
		{
			len--;
			res.pb(i);
			mx=a[i];
		}
	}
	return res;
}
