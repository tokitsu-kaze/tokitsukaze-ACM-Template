struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct Kruskal_Tree
{
	#define type int
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int x,int y,type w){e.push_back({x,y,w});}
	int build_kruskal_tree(int n,vector<int> *mp,type *w)
	{
		int rt,x,y,i;
		for(i=1;i<=2*n-1;i++)
		{
			mp[i].clear();
			w[i]=0;
		}
		dsu.init(2*n-1);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.w;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt,true);
			dsu.merge(y,rt,true);
		}
		return rt;
	}
	#undef type
}krsk;
