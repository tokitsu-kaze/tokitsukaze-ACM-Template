int mp[111][111],dis[111][111],ans;
void floyd(int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)
		{
			if(mp[k][i]==INF) continue;
			for(j=i+1;j<k;j++)
			{
				if(mp[k][j]==INF) continue;
				ans=min(ans,mp[k][i]+mp[k][j]+dis[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dis[i][k]==INF) continue;
			for(j=1;j<=n;j++)
			{
				if(dis[k][j]==INF) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main()
{
	int m,i,a,b,w,n;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0x3f);
		mem(dis,0x3f);
		ans=INF;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&w);
			mp[a][b]=mp[b][a]=dis[a][b]=dis[b][a]=min(mp[a][b],w);
		}
		floyd(n);
		if(ans==INF) puts("It's impossible.");
		else printf("%d\n",ans);
	}
	return 0;	
}
