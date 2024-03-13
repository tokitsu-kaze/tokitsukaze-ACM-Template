int p[MAX],phi[MAX],tot,prime[MAX];
void init_phi(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=phi[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			prime[i]=p[tot++]=i;
			phi[i]=i-1;
		}
		for(j=0;i*p[j]<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
