//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p[tot++]=i;
		for(j=i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
