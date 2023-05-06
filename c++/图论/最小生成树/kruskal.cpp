struct Disjoint_Set_Union
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
	#define type int
	#define inf INF
	struct edge
	{
		int x,y;
		type w;
	};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.pb({a,b,w});}
	type work(int n)
	{
		int i,cnt;
		type res=0;
		dsu.init(n);
		sort(all(e),[&](edge x,edge y){
			return x.w<y.w;
		});
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y)) res+=it.w;
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=dsu.find(i)==i;
		if(cnt!=1) return inf;
		return res;
	}
	#undef type
	#undef inf
}krsk;
