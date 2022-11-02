struct SPFA
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=MAX;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,vis[N],cnt[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].pb(MP(y,v));}
	bool work(int s)
	{
		int i,x,to,w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=cnt[i]=0;
		}
		dis[s]=0;
		vis[s]=1;
		q.push(s);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(auto it:mp[x])
			{
				to=it.fi;
				w=it.se;
				if(dis[to]>dis[x]+w)
				{
					dis[to]=dis[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>=n)
					{
						// cnt is edge counts of current short path
						// if cnt >=n, the graph exists negative ring
						return false;
					}
					if(!vis[to])
					{
						q.push(to);
						vis[to]=1;
					}
				}
			}
		}
		return true;
	}
	#undef type
	#undef inf
	#undef PTI
}spfa;
