struct leftist_tree
{
	#define type int
	struct node
	{
		int ls,rs,d,fa,id;
		type v;
		void init(){ls=rs=d=fa=id=v=0;}
	}t[MAX];
	int root[MAX],rt,tot,pos[MAX];
	int st[MAX],sttop;
	leftist_tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int n=1)
	{
		rt=1;
		tot=0;
		t[0].init();
		for(int i=0;i<=n;i++) root[i]=0;
	}
	int newnode(type v,int p)
	{
		int id=sttop?st[--sttop]:++tot;
		t[id].init();
		t[id].v=v;
		t[id].id=p;
		pos[p]=id;
		return id;
	}
	void delnode(int id){st[sttop++]=id;}
	int merge(int x,int y)
	{
		if(x==y) return x;
		if(!x||!y) return x+y;
		if(t[x].v<t[y].v) swap(x,y); // > small, < big
		t[x].rs=merge(t[x].rs,y);
		t[t[x].rs].fa=x;
		if(t[t[x].rs].d>t[t[x].ls].d) swap(t[x].ls,t[x].rs);
		t[x].d=t[t[x].rs].d+1;
		return x;
	}
	void erase_by_id(int id)
	{
		int x,y;
		x=pos[id];
		if(root[rt]==x)
		{
			pop();
			return;
		}
		delnode(x);
		pos[id]=0;
		y=merge(t[x].ls,t[x].rs);
		t[y].fa=t[x].fa;
		if(t[t[x].fa].ls==x) t[t[x].fa].ls=y;
		else if(t[t[x].fa].rs==x) t[t[x].fa].rs=y;
		x=t[y].fa;
		while(x)
		{
			if(t[x].d==t[t[x].rs].d+1) break;
			t[x].d=t[t[x].rs].d+1;
			x=t[x].fa;
		}
	}
	void del(int x)
	{
		if(!x) return;
		del(t[x].ls);
		del(t[x].rs);
		delnode(x);
	}
	void clear(){del(root[rt]);root[rt]=0;}
	void join(int y)
	{
		if(rt==y) return;
		root[rt]=merge(root[rt],root[y]);
		root[y]=0;
	}
	void push(type v,int p=0){root[rt]=merge(root[rt],newnode(v,p));}
	void pop()
	{
		int x=root[rt];
		pos[t[x].id]=0;
		root[rt]=merge(t[x].ls,t[x].rs);
		delnode(x);
	}
	node top(){return t[root[rt]];}
	bool empty(){return !root[rt];}
	void dfs(int x,type v)
	{
		if(!x) return;
		t[x].v+=v;
		dfs(t[x].ls,v);
		dfs(t[x].rs,v);
	}
	void updall(type v){dfs(root[rt],v);}
	node get_by_id(int id){return t[pos[id]];}
	#undef type
}q;
/*
q.init();
q.init(n);
q[x].push(x);
q[x].push(x,id);
q[x].top();
q[x].pop();
q[x].join(y);
q[x].clear();
q[x].erase_by_id(id);
*/
