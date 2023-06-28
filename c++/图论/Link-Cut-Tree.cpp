struct Link_Cut_Tree
{
	#define type int
	const type inf=INF;
	struct node
	{
		int ch[2],fa,sz,rev,tag;
		type v,sum;
	}t[MAX];
	int tot,root,st[MAX];
	void maintain(int id,type v)
	{
		t[id].v=v;
		t[id].sum=v;
	}
	void pushup(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		t[id].sz=t[ls].sz+t[rs].sz+1;
		t[id].sum=t[ls].sum+t[rs].sum+t[id].v;
	}
	void pushdown(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		if(t[id].tag)
		{
			if(ls)
			{
				maintain(ls,t[id].v);
				t[ls].tag=1;
			}
			if(rs)
			{
				maintain(rs,t[id].v);
				t[rs].tag=1;
			}
			t[id].tag=0;
		}
		if(t[id].rev)
		{
			t[ls].rev^=1;
			t[rs].rev^=1;
			swap(t[ls].ch[0],t[ls].ch[1]);
			swap(t[rs].ch[0],t[rs].ch[1]);
			t[id].rev=0;
		}
	}
	int newnode(type v,int fa)
	{
		int id=++tot;
		memset(t[id].ch,0,sizeof t[id].ch);
		t[id].fa=fa;
		t[id].sz=1;
		t[id].tag=t[id].rev=0;
		maintain(id,v);
		return id;
	}
	int is_splay_root(int x)
	{
		int fa=t[x].fa;
		return t[fa].ch[0]!=x&&t[fa].ch[1]!=x;
	}
	void rotate(int x)
	{
		int y,z,k;
		y=t[x].fa;
		z=t[y].fa;
		k=(x==t[y].ch[1]);
		if(!is_splay_root(y)) t[z].ch[y==t[z].ch[1]]=x;
		t[y].ch[k]=t[x].ch[k^1];
		if(t[x].ch[k^1]) t[t[x].ch[k^1]].fa=y;
		t[x].ch[k^1]=y;
		t[y].fa=x;
		t[x].fa=z;
		pushup(y);
	}
	void splay(int x)
	{
		int y,z,top;
		top=0;
		y=x;
		st[++top]=y;
		while(!is_splay_root(y))
		{
			y=t[y].fa;
			st[++top]=y;
		}
		while(top>0) pushdown(st[top--]);
		while(!is_splay_root(x))
		{
			y=t[x].fa;
			z=t[y].fa;
			if(!is_splay_root(y))
			{
				if((t[z].ch[0]==y)^(t[y].ch[0]==x)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		pushup(x);
	}
	void init_null_node()
	{
		memset(t[0].ch,0,sizeof t[0].ch);
		t[0].sz=t[0].fa=0;
		t[0].v=t[0].sum=0;
	}
	void init(int n,type *v)
	{
		int i;
		tot=0;
		init_null_node();
		for(i=1;i<=n;i++) newnode(v[i],0);
	}
	void init(int n)
	{
		int i;
		tot=0;
		init_null_node();
		for(i=1;i<=n;i++) newnode(0,0);
	}
	int access(int x)
	{
		int fa=0;
		while(x)
		{
			splay(x);
			t[x].ch[1]=fa;
			pushup(x);
			fa=x;
			x=t[x].fa;
		}
		return fa;
	}
	int findroot(int x)
	{
		access(x);
		splay(x);
		pushdown(x);
		while(t[x].ch[0])
		{
			x=t[x].ch[0];
			pushdown(x);
		}
		splay(x);
		return x;
	}
	void makeroot(int x)
	{
		x=access(x);
		swap(t[x].ch[0],t[x].ch[1]);
		t[x].rev^=1;
	}
	int split(int x,int y)
	{
		makeroot(x);
		access(y);
		splay(y);
		return y;
	}
	void link(int x,int y)
	{
		makeroot(x);
		splay(x);
		if(findroot(y)!=x) t[x].fa=y;
	}
	void cut(int x,int y)
	{
		makeroot(x);
		if(findroot(y)==x&&t[y].fa==x&&t[y].ch[0]==0)
		{
			t[y].fa=t[x].ch[1]=0;
			pushup(x);
		}
	}
	int is_connect(int x,int y)
	{
		makeroot(x);
		return findroot(y)==x;
	}
	void upd_node(int x,type v)
	{
		splay(x);
		maintain(x,v);
	}
	#undef type
}lct;
/*
lct.init(n);
lct.init(n,*v); v[1..n]
*/
