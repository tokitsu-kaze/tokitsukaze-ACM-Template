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
		edge.push_back(node(from,to,cap,cost));
		edge.push_back(node(to,from,0,-cost));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool dij()
	{
		int i,x,to;
		type cost,now_cost;
		for(i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push({type(0),s});
		while(!q.empty())
		{
			PTI tmp=q.top();
			q.pop();
			cost=tmp.first;
			x=tmp.second;
			if(cost>dis[x]) continue;
			for(i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				to=e.to;
				type now_cost=e.cost+h[x]-h[to];
				if(e.flow>0&&dis[to]>dis[x]+now_cost)
				{
					dis[to]=dis[x]+now_cost;
					q.push({dis[to],to});
					e.from=x;
					id[to]=mp[x][i];
				}
			}
		}
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		for(int i=0;i<=n;i++) h[i]=0;
		s=_s;
		t=_t;
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
		return {cost,flow};
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf; //upper: O(nmlog(nm) + max_flow*mlogm)
