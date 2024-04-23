void sosdp(int n)
{
	int i,j;
	for(j=0;j<n;j++)
	{
		for(i=0;i<(1<<n);i++)
		{
			if((i>>j)&1) dp[i]+=dp[i^(1<<j)];
		}
	}
}
