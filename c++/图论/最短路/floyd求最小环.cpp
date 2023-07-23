struct Floyd
{
	#define type int
	const type inf=INF;
	static const int N=;
	int n;
	type mp[N][N],dis[N][N];
	type min_circle_3;// len(circle)>=3
	type min_circle;  // len(circle)>=1
	void init(int _n)
	{
		int i,j;
		n=_n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]=dis[i][j]=inf;
			}
		}
	}
	void add_edge(int x,int y,type w)
	{
		w=min(mp[x][y],w);
		mp[x][y]=dis[x][y]=w;
	}
	void work()
	{
		int i,j,k;
		min_circle_3=inf;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<k;i++)
			{
				if(mp[i][k]==INF) continue;
				for(j=1;j<k;j++)
				{
					if(i==j||mp[k][j]==INF||dis[j][i]==INF) continue;
					min_circle_3=min(min_circle_3,mp[i][k]+mp[k][j]+dis[j][i]);
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
		min_circle=inf;
		for(i=1;i<=n;i++) min_circle=min(min_circle,dis[i][i]);
	}
	#undef type
}flyd;
/*
flyd.init(n);
flyd.add_edge(x,y,w); x,y [1..n] x->y 
flyd.work();
*/
