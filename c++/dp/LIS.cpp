vector<int> LIS(vector<int> a)
{
	int i,pos,len,mx,n;
	n=a.size();
	vector<int> b(n,INF),tmp(n),res;
	for(i=0;i<n;i++)
	{
		//    strict: lower_bound
		//not strict: upper_bound
		pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		b[pos]=a[i];
		tmp[i]=pos;
	}
	len=lower_bound(b.begin(),b.end(),INF)-b.begin();
	mx=INF;
	for(i=n-1;~i;i--)
	{
		if(!len) break;
		//    strict LIS: >
		//not strict LIS: >=
		if(tmp[i]+1==len&&mx>a[i])
		{
			len--;
			res.push_back(i);
			mx=a[i];
		}
	}
	return res;
}
