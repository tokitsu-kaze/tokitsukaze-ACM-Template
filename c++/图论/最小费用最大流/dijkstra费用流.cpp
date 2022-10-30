struct MCMF_dij
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=;
	struct node
	{
		int from,to;
		type flow,cost;
		node(){}
		node(int u,int v,type f,type co):from(u),to(v),flow(f),cost(co){}
	};
	int n,s,t,id[N];
	vector<node> edge;
	vector<int> mp[N];
	type dis[N],h[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost=0)
	{
		edge.pb(node(from,to,cap,cost));
		edge.pb(node(to,from,0,-cost));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool dij(type& flow,type& cost)
	{
		for(int i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI x=q.top();
			q.pop();
			if(x.fi>dis[x.se]) continue;
			for(int i=0;i<mp[x.se].size();i++)
			{
				node& e=edge[mp[x.se][i]];
				int to=e.to;
				type now_cost=e.cost+h[x.se]-h[to];
				if(e.flow>0&&dis[to]>dis[x.se]+now_cost)
				{ 
					dis[to]=dis[x.se]+now_cost;
					q.push(MP(dis[to],to));
					e.from=x.se;
					id[to]=mp[x.se][i];
				}
			}
		}
		if(dis[t]==inf) return false;
		for(int i=0;i<=n;i++) h[i]=min(h[i]+dis[i],inf);
		type new_flow=inf;
		int x=t;
		while(x!=s)
		{
			new_flow=min(new_flow,edge[id[x]].flow);
			x=edge[id[x]].from;
		}
		flow+=new_flow;
		cost+=new_flow*h[t];
		x=t;
		while(x!=s)
		{
			edge[id[x]].flow-=new_flow;
			edge[id[x]^1].flow+=new_flow;
			x=edge[id[x]].from;
		}
		return true;
	}
	//O(m*logm*max_flow)
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		type flow=0,cost=0;
		for(int i=0;i<=n;i++) h[i]=0;
		s=_s;
		t=_t;
		while(dij(flow,cost));
		return MP(cost,flow);
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf;
