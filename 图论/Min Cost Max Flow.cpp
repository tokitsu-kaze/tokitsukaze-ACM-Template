struct MCMF
{
	#define type int //int->INF	ll->LLINF
	static const int N=2005;
	struct node
	{
		int from,to;
		type cap,flow,cost;
		node(){}
		node(int u,int v,type c,type f,type co):from(u),to(v),cap(c),flow(f),cost(co){}
	};
	int n,s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],id[N];
	type d[N],a[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add(int from,int to,type cap,type cost=0)
	{
		edge.pb(node(from,to,cap,0,cost));
		edge.pb(node(to,from,0,0,-cost));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool spfa(type& flow,type& cost)
	{
		for(int i=0;i<=n;i++)
		{
			d[i]=INF;
			vis[i]=0;
		}
		d[s]=0;vis[s]=1;id[s]=0;a[s]=INF;
		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(int i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				int to=e.to;
				if(e.cap>e.flow&&d[to]>d[x]+e.cost)
				{ 
					d[to]=d[x]+e.cost;
					a[to]=min(a[x],e.cap-e.flow);
					id[to]=mp[x][i];
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
		if(d[t]==INF) return false;
		flow+=a[t];
		cost+=a[t]*d[t];
		int x=t;
		while(x!=s)
		{
			edge[id[x]].flow+=a[t];
			edge[id[x]^1].flow-=a[t];
			x=edge[id[x]].from;
		}
		return true;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		type flow=0,cost=0;
		s=_s;
		t=_t;
		while(spfa(flow,cost));
		return MP(cost,flow);
	}
	#undef type
}mcmf;
