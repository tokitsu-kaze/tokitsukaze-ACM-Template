struct Segment_Tree
{
	#define type int
	static const int LOG=31;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	type ql,qr,qv,n,tag[MAX*LOG];
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(type _n)
	{
		n=_n;
		rt=1;
		tot=top=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(){root[rt]=0;}
	void delnode(int id){st[top++]=id;}
	int newnode()
	{
		int id;
		id=top?st[--top]:++tot;
		t[id].init();
		ls[id]=rs[id]=0;
		tag[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		//
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(type l,type r,int id)
	{
		if(!tag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=0;
	}
	void update(type l,type r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			//
			return;
		}
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(type l,type r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	int split(type l,type r,int &id)
	{
		int x;
		if(!id) return 0;
		if(l>=ql&&r<=qr)
		{
			x=id;
			id=0;
			return x;
		}
		x=newnode();
		int mid=(l+r)>>1;
		if(ql<=mid) ls[x]=split(l,mid,ls[id]);
		if(qr>mid) rs[x]=split(mid+1,r,rs[id]);
		pushup(x);
		pushup(id);
		return x;
	}
	int merge(type l,type r,int x,int y)
	{
		if(!x||!y) return x+y;
		if(l==r)
		{
			//merge info x <- y
			delnode(y);
			return x;
		}
		type mid=(l+r)>>1;
		ls[x]=merge(l,mid,ls[x],ls[y]);
		rs[x]=merge(mid+1,r,rs[x],rs[y]);
		pushup(x);
		delnode(y);
		return x;
	}
	void split_segtree(type l,type r,int new_tree)
	{
		ql=l;
		qr=r;
		root[new_tree]=split(1,n,root[rt]);
	}
	void merge_segtree(int y)
	{
		root[rt]=merge(1,n,root[rt],root[y]);
		root[y]=0;
	}
	void upd(type l,type r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	type ask(type l,type r)
	{
		ql=l;
		qr=r;
		return query(1,n,root[rt]).v;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
---------
tr[x].build();
tr[x].merge_segtree(y);
tr[x].split_segtree(l,r,new_tree);
*/
