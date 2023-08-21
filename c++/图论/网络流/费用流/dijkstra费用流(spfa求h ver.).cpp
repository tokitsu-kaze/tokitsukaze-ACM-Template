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
	int n,s,t,id[N],vis[N];
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
	void spfa()
	{
		int i,x,to;
		for(i=0;i<=n;i++)
		{
			h[i]=inf;
			vis[i]=0;
		}
		queue<int> q;
		q.push(s);
		h[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(i=0;i<sz(mp[x]);i++)
			{
				node &e=edge[mp[x][i]];
				to=e.to;
				if(e.flow>0&&h[to]>h[x]+e.cost)
				{ 
					h[to]=h[x]+e.cost;
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
	}
	bool dij()
	{
		int i,to;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI x=q.top();
			q.pop();
			if(vis[x.se]) continue;
			vis[x.se]=1;
			for(i=0;i<sz(mp[x.se]);i++)
			{
				node& e=edge[mp[x.se][i]];
				to=e.to;
				type now_cost=e.cost+h[x.se]-h[to];
				if(e.flow>0&&dis[to]>dis[x.se]+now_cost)
				{ 
					dis[to]=dis[x.se]+now_cost;
					e.from=x.se;
					id[to]=mp[x.se][i];
					if(!vis[to]) q.push(MP(dis[to],to));
				}
			}
		}
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		s=_s;
		t=_t;
		spfa();
		while(dij())
		{
			for(i=0;i<=n;i++) h[i]+=dis[i];
			type new_flow=inf;
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				new_flow=min(new_flow,edge[id[i]].flow);
			}
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				edge[id[i]].flow-=new_flow;
				edge[id[i]^1].flow+=new_flow;
			}
			flow+=new_flow;
			cost+=new_flow*h[t];
		}
		return MP(cost,flow);
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf; // upper: O(nm + max_flow*mlogm)
