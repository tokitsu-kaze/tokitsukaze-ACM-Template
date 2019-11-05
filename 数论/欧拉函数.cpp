//欧拉函数 (<=n且与n互质的数的和：n*phi[n]/2)
//1.直接求某个数的欧拉函数 O(sqrt(n))
int euler(int n)
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
//2.线性筛 O(n)
int prime[MAX],phi[MAX],tot;
bool flag[MAX];
void init(int n)  
{  
	int i,j,k;
	tot=0;  
	mem(flag,0);
	phi[0]=0;
	phi[1]=1;
	for(i=2;i<=n;i++)  
	{  
		if(!flag[i])  
		{  
			prime[tot++]=i;  
			phi[i]=i-1;
		}  
		for(j=0;j<tot&&i*prime[j]<=n;j++)  
		{  
			k=i*prime[j];
			flag[k]=1;
			if(i%prime[j]==0)
			{  
				phi[k]=phi[i]*prime[j];
				break;
			}
			else phi[k]=phi[i]*(prime[j]-1);
		}
	}
}
