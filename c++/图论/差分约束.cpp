struct Difference_Constraints
{
	#define type int
	static const int inf=INF;
	static const int N=5005;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,s,vis[N],cnt[N];
	void init(int _n)
	{
		s=_n+1;
		n=s;
		for(int i=0;i<=n;i++) mp[i].clear();
		
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	bool work()
	{
		int i,x,to;
		type w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=cnt[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(i==s) continue;
			add_edge(s,i,0);
		}
		vis[s]=1;
		dis[s]=0;
		q.push(s);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(auto &it:mp[x])
			{
				to=it.first;
				w=it.second;
				if(dis[to]>dis[x]+w)
				{
					dis[to]=dis[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>n) return false;
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
}dfct;
/*
O(n*m)
dfct.init(n);  x[1],x[2],...,x[n]
dfct.add_edge(a,b,val); -> x[a]+val>=x[b]
dfct.work();
*/
