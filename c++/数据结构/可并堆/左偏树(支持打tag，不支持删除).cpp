struct leftist_tree
{
	#define type ll
	struct node
	{
		int ls,rs,d,id;
		type v;
		void init(){ls=rs=d=id=v=0;}
	}t[MAX];
	int root[MAX],rt,tot,sz[MAX];
	type tagadd[MAX],tagmul[MAX];
	leftist_tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int n=1)
	{
		rt=1;
		tot=0;
		t[0].init();
		sz[0]=0;
		for(int i=0;i<=n;i++) root[i]=0;
	}
	int newnode(type v,int p)
	{
		int id=++tot;
		t[id].init();
		t[id].id=p;
		t[id].v=v;
		sz[id]=1;
		tagadd[id]=0;
		tagmul[id]=1;
		return id;
	}
	void pushdown(int id)
	{
		int ls=t[id].ls;
		int rs=t[id].rs;
		if(tagmul[id]!=1)
		{
			if(ls)
			{
				t[ls].v*=tagmul[id];
				tagmul[ls]*=tagmul[id];
				tagadd[ls]*=tagmul[id];
			}
			if(rs)
			{
				t[rs].v*=tagmul[id];
				tagmul[rs]*=tagmul[id];
				tagadd[rs]*=tagmul[id];
			}
			tagmul[id]=1;
		}
		if(tagadd[id])
		{
			if(ls)
			{
				t[ls].v+=tagadd[id];
				tagadd[ls]+=tagadd[id];
			}
			if(rs)
			{
				t[rs].v+=tagadd[id];
				tagadd[rs]+=tagadd[id];
			}
			tagadd[id]=0;
		}
	}
	int merge(int x,int y)
	{
		if(x==y) return x;
		if(!x||!y) return x+y;
		if(t[x].v>t[y].v) swap(x,y); // > small, < big
		pushdown(x);
		t[x].rs=merge(t[x].rs,y);
		if(t[t[x].rs].d>t[t[x].ls].d) swap(t[x].ls,t[x].rs);
		t[x].d=t[t[x].rs].d+1;
		sz[x]=sz[t[x].ls]+sz[t[x].rs]+1;
		return x;
	}
	void clear(){root[rt]=0;}
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
		pushdown(x);
		root[rt]=merge(t[x].ls,t[x].rs);
	}
	node top(){return t[root[rt]];}
	bool empty(){return !root[rt];}
	int size(){return sz[root[rt]];}
	void upd(int op,type v)
	{
		int x=root[rt];
		if(op==0)
		{
			tagadd[x]+=v;
			t[x].v+=v;
		}
		else
		{
			tagadd[x]*=v;
			tagmul[x]*=v;
			t[x].v*=v;
		}
	}
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
*/
