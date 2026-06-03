struct Edge{int x,y;};
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qlimt;
	Edge qv;
	struct node
	{
		vector<Edge> v;
		void init(){v.clear();}
	}t[MAX<<2];
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].v.push_back(qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void dfs(int l,int r,int id)
	{
		if(l>r) return;
		for(auto &it:t[id].v) dsu.merge(it.x,it.y);
		if(l==r)
		{
			dsu.upd(1,l);
			for(auto &it:t[id].v) dsu.roll_back();
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
		for(auto &it:t[id].v) dsu.roll_back();
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
	}
	void upd(int l,int r,Edge v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void ask()
	{
		dfs(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
