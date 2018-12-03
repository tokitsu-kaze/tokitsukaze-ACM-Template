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
struct node
{
	int x,y,w;
	node(){}
	node(int a,int b,int c):x(a),y(b),w(c){}
	friend bool operator<(node a,node b) {return a.w<b.w;}
};
vector<node> edge;
int kruskal(int n)
{
	int res=0;
	dsu.init(n);
	sort(all(edge));
	for(int i=0;i<sz(edge);i++)
	{
		if(dsu.merge(edge[i].x,edge[i].y)) res+=edge[i].w;
	}
	return res;
}
