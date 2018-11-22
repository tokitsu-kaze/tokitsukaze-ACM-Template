struct ISAP
{
	static const int N=100010;
	struct node
	{
		int from,to,cap,flow;
		node(){}
		node(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
	};
	int p[N],num[N],cur[N],d[N];
	int t,s,n;
	bool vis[N];
	vector<int> mp[N];
	vector<node> edge;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			d[i]=INF;
			vis[i]=num[i]=cur[i]=0;
		}
		edge.clear();
	}
	void add(int from,int to,int cap)
	{
		edge.pb(node(from,to,cap,0));
		edge.pb(node(to,from,0,0));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool bfs()
	{
		queue<int> q;
		d[t]=0;
		vis[t]=1;
		q.push(t);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<mp[u].size();i++)
			{
				node &e=edge[mp[u][i]^1];
				if(!vis[e.from]&&e.cap>e.flow)
				{
					vis[e.from]=true;
					d[e.from]=d[u]+1;
					q.push(e.from);
				}
			}
		}
		return vis[s];
	}
	int augment()
	{
		int u=t,flow=INF;
		while(u!=s)
		{
			node &e=edge[p[u]];
			flow=min(flow,e.cap-e.flow);
			u=edge[p[u]].from;
		}
		u=t;
		while(u!=s)
		{
			edge[p[u]].flow+=flow;
			edge[p[u]^1].flow-=flow;
			u=edge[p[u]].from;
		}
		return flow;
	}
	int maxflow(int _s,int _t)
	{
		s=_s;
		t=_t;
		int flow=0;
		bfs();
		if(d[s]>=n) return 0;
		for(int i=0;i<n;i++)
		{
			if(d[i]<INF) num[d[i]]++;
		}
		int u=s;
		while(d[s]<n)
		{
			if(u==t)
			{
				flow+=augment();
				u=s;
			}
			bool ok=false;
			for(int i=cur[u];i<mp[u].size();i++)
			{
				node &e=edge[mp[u][i]];
				if(e.cap>e.flow&&d[u]==d[e.to]+1)
				{
					ok=true;
					p[e.to]=mp[u][i]; 
					cur[u]=i;
					u=e.to;
					break;
				}
			}
			if(!ok)
			{
				int mn=n-1;
				for(int i=0;i<mp[u].size();i++)
				{
					node &e=edge[mp[u][i]];
					if(e.cap>e.flow) mn=min(mn,d[e.to]);
				}
				if(--num[d[u]]==0) break;
				num[d[u]=mn+1]++;
				cur[u]=0;
				if(u!=s) u=edge[p[u]].from;
			}
		}
		return flow;
	}
}isap;
