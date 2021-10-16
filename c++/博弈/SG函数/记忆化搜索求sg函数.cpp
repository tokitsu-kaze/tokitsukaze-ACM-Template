int f[105],sg[MAX],m;
int dfs(int x)
{
	int i,j,flag[105];
	if(sg[x]!=-1) return sg[x];
	mem(flag,0);
	for(i=1;i<=m;i++)
	{
		if(x>=f[i])
		{
			dfs(x-f[i]);
			flag[sg[x-f[i]]]=1;
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