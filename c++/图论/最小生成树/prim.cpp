struct Prim
{
	#define type int
	const type inf=INF;
	struct node{int id;type w;};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type w)
	{
		mp[x].push_back({y,w});
		mp[y].push_back({x,w});
	}
	type work()
	{
		int i,x,cnt;
		type res,mn;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		x=1;
		for(auto &to:mp[x]) dis[to.id]=min(dis[to.id],to.w);
		res=0;
		cnt=0;
		while(1)
		{
			mn=inf;
			vis[x]=1;
			cnt++;
			for(i=1;i<=n;i++)
			{
				if(!vis[i]&&dis[i]<mn)
				{
					mn=dis[i];
					x=i;
				}
			}
			if(mn==inf) break;
			res+=mn;
			for(auto &to:mp[x]) dis[to.id]=min(dis[to.id],to.w);
		}
		if(cnt<n) return inf; // no connect
		return res;
	}
	#undef type
}prim;
/*
O(n^2+m)

prim.init(n);
prim.add_edge(x,y,w);  x<->y
prim.work();
*/
