int sg[MAX],a[MAX],n;
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	int i,j,flag[105];
	memset(flag,0,sizeof flag);
	for(i=1;i<=n;i++)
	{
		if(x>=a[i])
		{
			dfs(x-a[i]);
			flag[sg[x-a[i]]]=1;
		}
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
