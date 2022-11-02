struct Johnson
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=3000+10;
	vector<pair<int,type> > mp[N];
	type dis[N],h[N];
	int n,vis[N],cnt[N];
	bool spfa_flag;
	void init(int _n)
	{
		n=_n;
		spfa_flag=false;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].pb(MP(y,v));}
	bool spfa(int s)
	{
		int i,x,to;
		type w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			h[i]=inf;
			vis[i]=cnt[i]=0;
		}
		h[s]=0;
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
				if(h[to]>h[x]+w)
				{
					h[to]=h[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>n)
					{
						// cnt is edge counts of current short path
						// if cnt >= (sum of node), the graph exists negative ring
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
		spfa_flag=true;
		return true;
	}
	void dij(int s)
	{
		assert(spfa_flag);
		int i,to;
		type w;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI t=q.top();
			q.pop();
			if(vis[t.se]) continue;
			vis[t.se]=1;
			for(auto it:mp[t.se])
			{
				to=it.fi;
				w=it.se+h[t.se]-h[to];
				if(dis[to]>dis[t.se]+w)
				{
					dis[to]=dis[t.se]+w;
					if(!vis[to]) q.push(MP(dis[to],to));
				}
			}
		}
		for(i=0;i<=n;i++)
		{
			if(dis[i]==inf) continue;
			dis[i]-=h[s]-h[i];
		}
	}
	#undef type
	#undef inf
	#undef PTI
}js;
