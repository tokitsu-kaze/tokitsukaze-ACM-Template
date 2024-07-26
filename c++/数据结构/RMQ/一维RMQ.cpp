struct ST_table
{
	#define type int
	type v[MAX];
	int pmax(int a,int b){return v[a]>v[b]?a:b;}
	int pmin(int a,int b){return v[a]<v[b]?a:b;}
	int lg[MAX],bin[22];
	int pmx[MAX][22],pmn[MAX][22];
	type mx[MAX][22],mn[MAX][22];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			mx[i][0]=mn[i][0]=v[i];
			pmx[i][0]=pmn[i][0]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
				mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
				pmx[i][j]=pmax(pmx[i][j-1],pmx[i+bin[j-1]][j-1]);
				pmn[i][j]=pmin(pmn[i][j-1],pmn[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_max(int l,int r)
	{
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	type ask_min(int l,int r)
	{
		int t=lg[r-l+1];
		return min(mn[l][t],mn[r-bin[t]+1][t]);
	}
	int ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[l][t],pmx[r-bin[t]+1][t]);
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[l][t],pmn[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
