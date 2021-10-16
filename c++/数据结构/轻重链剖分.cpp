struct HLD
{
	#define type int
	struct edge{int a,b;type v;edge(int _a,int _b,type _v=0):a(_a),b(_b),v(_v){}};
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	vector<int> mp[MAX];
	vector<edge> e;
	int deep[MAX],fa[MAX],size[MAX],son[MAX];
	int rnk[MAX],top[MAX],idx[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.pb(edge(0,0));
	}
	void add_edge(int a,int b,type v=0)
	{
		e.pb(edge(a,b,v));
		mp[a].pb(b);
		mp[b].pb(a);
	}
	void dfs1(int x,int pre,int h)  
	{
		int i,to;
		deep[x]=h;
		fa[x]=pre;
		size[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			size[x]+=size[to];
			if(son[x]==-1||size[to]>size[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		top[x]=tp;
		idx[x]=++tot;
		rnk[idx[x]]=x;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt) 
	{
		int i;
		rt=_rt;
		mem(son,-1);
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    return x;
	}
	//node
	void init_node()
	{
		build(n);
	}
	void modify_node(int x,int y,type val)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			update(idx[top[x]],idx[x],val);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    update(idx[x],idx[y],val);
	}
	type query_node(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res+=query(idx[top[x]],idx[x]);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    res+=query(idx[x],idx[y]);
	    return res;
	}
	//path
	void init_path()
	{
		v[idx[rt]]=0;
		for(int i=1;i<n;i++)
		{
			if(deep[e[i].a]<deep[e[i].b]) swap(e[i].a,e[i].b);
			v[idx[e[i].a]]=e[i].v;
		}
		build(n);
	}
	void modify_edge(int id,type val)
	{
		if(deep[e[id].a]>deep[e[id].b]) update(idx[e[id].a],idx[e[id].a],val);
		else update(idx[e[id].b],idx[e[id].b],val);
	}
	void modify_path(int x,int y,type val)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			update(idx[top[x]],idx[x],val);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) update(idx[x]+1,idx[y],val);
	}
	type query_path(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res+=query(idx[top[x]],idx[x]);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) res+=query(idx[x]+1,idx[y]);
	    return res;
	}
	#undef type
}hld;
/***********attention!************/
//hld.init(n)
//hld.add_edge(): undirected edge.
/*********************************/
