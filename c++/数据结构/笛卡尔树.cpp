namespace Cartesian_Tree
{
	int l[MAX],r[MAX],vis[MAX],stk[MAX];
	int build(int *a,int n)
	{
		int i,top=0;
		for(i=1;i<=n;i++) l[i]=0,r[i]=0,vis[i]=0;
		for(i=1;i<=n;i++)
		{
			int k=top;
			while(k>0&&a[stk[k-1]]>a[i]) k--;
			if(k) r[stk[k-1]]=i;
			if(k<top) l[i]=stk[k];
			stk[k++]=i;
			top=k;
		}
		for(i=1;i<=n;i++) vis[l[i]]=vis[r[i]]=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) return i;
		}
	}
}
