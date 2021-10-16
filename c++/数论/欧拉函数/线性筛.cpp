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
