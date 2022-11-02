struct Dijkstra
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=MAX;
	vector<pair<int,type> > mp[N];
	type dist[N];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].pb(MP(y,v));}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		for(i=0;i<=n;i++) dist[i]=inf;
		dist[s]=0;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI t=q.top();
			q.pop();
			if(t.fi>dist[t.se]) continue;
			for(auto it:mp[t.se])
			{
				to=it.fi;
				w=it.se;
				if(dist[to]>dist[t.se]+w)
				{
					dist[to]=dist[t.se]+w;
					q.push(MP(dist[to],to));
				}
			}
		}
	}
	#undef type
	#undef inf
	#undef PTI
}dij;
