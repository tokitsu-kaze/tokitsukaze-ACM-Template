//O(sqrt(n))
int get_phi(int n)
{
	int ans,i;
	ans=n;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans=ans-ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans-ans/n;
	return ans;
}
