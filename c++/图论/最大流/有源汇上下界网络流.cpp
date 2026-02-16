struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=;
	struct node
	{
		int from,to;
		type cap,flow;
		node(int u,int v,type c,type f):from(u),to(v),cap(c),flow(f){}
	};
	int n,m,s,t,s1,t1;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],dist[N],id[N];
	type in[N],out[N];
	void init(int _n)
	{
		s1=_n+1;
		t1=s1+1;
		n=t1;
		assert(n<N);
		edge.clear();
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			id[i]=dist[i]=0;
			in[i]=out[i]=0;
		}
	}
	void add_edge(int from,int to,type lcap,type rcap)
	{
		edge.push_back(node(from,to,rcap-lcap,0));
		edge.push_back(node(to,from,0,0));
		in[to]+=lcap;
		out[from]+=lcap;
		m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool bfs()
	{
		int i,x;
		for(int i=0;i<=n;i++) vis[i]=0;
		queue<int>q;
		q.push(s);
		dist[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<mp[x].size();i++)
			{
				node &e=edge[mp[x][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=1;
					dist[e.to]=dist[x]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	type dfs(int x,type a)
	{
		if(x==t||!a) return a;
		type flow=0,f;
		for(int &i=id[x];i<mp[x].size();i++)
		{
			node &e=edge[mp[x][i]];
			if(dist[x]+1==dist[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edge[mp[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a) break;
			}
		}
		return flow;
	}
	type dinic(int _s,int _t)
	{
		int i;
		s=_s;
		t=_t;
		type res=0;
		while(bfs())
		{
			for(i=0;i<=n;i++) id[i]=0;
			res+=dfs(s,inf);
		}
		return res;
	}
	type work(int _s,int _t)
	{
		int i;
		s=s1;
		t=t1;
		for(i=0;i<s1;i++)
		{
			if(in[i]>out[i]) add_edge(s,i,0,in[i]-out[i]);
			else if(in[i]<out[i]) add_edge(i,t,0,out[i]-in[i]);
		}
		add_edge(_t,_s,0,inf);
		dinic(s,t);
		for(i=0;i<mp[s].size();i++)
		{
			node &e=edge[mp[s][i]];
			if(e.cap-e.flow!=0) return -inf;
		}
		s=_s;
		t=_t;
		type res=edge[m-2].flow;
		edge[m-2].flow=edge[m-1].flow=0;
		edge[m-2].cap=edge[m-1].cap=0;
		return res;
	}
	type max_flow(int _s,int _t)
	{
		type res=work(_s,_t);
		if(res==-inf) return -inf;
		return res+dinic(_s,_t);
	}
	type min_flow(int _s,int _t)
	{
		type res=work(_s,_t);
		if(res==-inf) return -inf;
		return res-dinic(_t,_s);
	}
	#undef type
}dc; 
/*
dc.init(n);
dc.add_edge(a,b,lcap,rcap); a,b: 1~n
dc.max_flow(s,t);
dc.min_flow(s,t);
return -inf: no solution
*/
