struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	struct node{int to;type w;};
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
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
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
	void upd_subtree(int x,type v){tr.upd(dfn[x],dfn[x]+sz[x]-1,v);}
	type ask_subtree(int x){return tr.ask(dfn[x],dfn[x]+sz[x]-1);}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(root);
*/

