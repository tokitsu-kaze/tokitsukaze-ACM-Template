struct dsu
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct Kruskal
{
	#define type ll
	#define inf LLINF
	vector<pair<type,PII> > e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.pb(MP(w,MP(a,b)));}
	type work(int n)
	{
		int x,y,i,cnt;
		type w;
		type res=0;
		dsu.init(n);
		sort(all(e));
		for(auto it:e)
		{
			x=it.se.fi;
			y=it.se.se;
			w=it.fi;
			if(dsu.merge(x,y)) res+=w;
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=dsu.find(i)==i;
		if(cnt!=1) return inf;
		return res;
	}
	#undef type
	#undef inf
}krsk;
