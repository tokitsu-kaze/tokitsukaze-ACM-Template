struct Cartesian_Tree
{
	int ls[MAX],rs[MAX],vis[MAX],st[MAX],top;
	int build_tree(int n,int *a)
	{
		int i,k;
		top=0;
		for(i=1;i<=n;i++) ls[i]=rs[i]=vis[i]=0;
		for(i=1;i<=n;i++)
		{
			k=top;
			while(k>0&&a[st[k-1]]>a[i]) k--;
			if(k) rs[st[k-1]]=i;
			if(k<top) ls[i]=st[k];
			st[k++]=i;
			top=k;
		}
		for(i=1;i<=n;i++) vis[ls[i]]=vis[rs[i]]=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) return i;
		}
		return -1;
	}
}ct;
