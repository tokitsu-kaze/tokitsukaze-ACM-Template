struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	vector<int> mp[MAX];
	vector<edge> e;
	int dep[MAX],fa[MAX],sz[MAX],son[MAX];
	int id[MAX],top[MAX],dfn[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.push_back({0,0,0});
	}
	void add_edge(int a,int b,type v=0)
	{
		e.push_back({a,b,v});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void dfs1(int x,int pre,int h)
	{
		int i,to;
		dep[x]=h;
		fa[x]=pre;
		sz[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			sz[x]+=sz[to];
			if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		dfn[x]=++tot;
		id[dfn[x]]=x;
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt)
	{
		rt=_rt;
		for(int i=0;i<=n;i++) son[i]=-1;
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	int find_yson_toward_x(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(fa[top[x]]==y) return top[x];
			x=fa[top[x]];
		}
	    return son[y];
	}
	//node
	void init_node(type *v)
	{
		for(int i=1;i<=n;i++) tr.a[dfn[i]]=v[i];
		tr.build(n);
	}
	void upd_node(int x,int y,type v)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    tr.upd(dfn[x],dfn[y],v);
	}
	type ask_node(int x,int y)
	{
		type res=0;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res+=tr.ask(dfn[top[x]],dfn[x]);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    res+=tr.ask(dfn[x],dfn[y]);
	    return res;
	}
	//path
	void init_path()
	{
		tr.a[dfn[rt]]=0;
		for(int i=1;i<n;i++)
		{
			if(dep[e[i].a]<dep[e[i].b]) swap(e[i].a,e[i].b);
			tr.a[dfn[e[i].a]]=e[i].v;
		}
		tr.build(n);
	}
	void upd_edge(int id,type v)
	{
		if(dep[e[id].a]>dep[e[id].b]) tr.upd(dfn[e[id].a],dfn[e[id].a],v);
		else tr.upd(dfn[e[id].b],dfn[e[id].b],v);
	}
	void upd_path(int x,int y,type v)
	{  
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) tr.upd(dfn[x]+1,dfn[y],v);
	}
	type ask_path(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res+=tr.ask(dfn[top[x]],dfn[x]);
			x=fa[top[x]];
		}  
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) res+=tr.ask(dfn[x]+1,dfn[y]);
	    return res;
	}
	// sub tree
	void change_root(int x){rt=x;}
	void upd_subtree(int x,type v)
	{
		if(x==rt) tr.upd(1,n,v);
		else if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			tr.upd(1,dfn[x]-1,v);
			tr.upd(dfn[x]+sz[x],n,v);
		}
		else tr.upd(dfn[x],dfn[x]+sz[x]-1,v);
	}
	type ask_subtree(int x)
	{
		if(x==rt) return tr.ask(1,n).v;
		if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			return tr.merge(tr.ask(1,dfn[x]-1),
							tr.ask(dfn[x]+sz[x],n)).v;
		}
		return tr.ask(dfn[x],dfn[x]+sz[x]-1).v;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.lca(a,b);
---- node ----
hld.init_node(type *v);
hld.upd_node(a,b,v);
hld.ask_node(a,b);
---- path ----
hld.init_path();
hld.upd_edge(id,v);   id:1..n-1
hld.upd_path(a,b,v);
hld.ask_path(a,b);
---- subtree ----
hld.change_root(rt);
hld.upd_subtree(x,v);
hld.ask_subtree(x);
*/

