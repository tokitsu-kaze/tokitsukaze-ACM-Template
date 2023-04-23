vector<int> LIS(vector<int> a,bool strict)
{
	int i,pos,len,n;
	n=a.size();
	vector<int> b(n,INF),tmp(n),res;
	for(i=0;i<n;i++)
	{
		//    strict: lower_bound
		//not strict: upper_bound
		if(strict) pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		else pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
		b[pos]=a[i];
		tmp[i]=pos;
	}
	len=lower_bound(b.begin(),b.end(),INF)-b.begin();
	for(i=n-1;~i;i--)
	{
		if(!len) break;
		if(tmp[i]+1==len)
		{
			len--;
			res.push_back(i);
		}
	}
	return res;
}
