//Äª±ÈÎÚË¹º¯Êý 
int mo[MAX],prime[MAX],tot;
bool flag[MAX];
void initmo(int n)
{
	int i,j;
	mem(flag,0);
	mem(mo,0);
	tot=0;
	mo[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[tot++]=i;
			mo[i]=-1;
		}
		for(j=0;j<tot&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mo[prime[j]*i]=0;
				break;
			}
			mo[prime[j]*i]=-mo[i];
		}
	}
}
