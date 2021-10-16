//空间大小是nlogm,n为插入的节点总数,m为区间长度 
struct Segment_Tree
{
	#define type int
	int root,tot,ls[MAX*20],rs[MAX*20],ql,qr,n;
	type v[MAX*20],tag[MAX*20],qv;
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		tag[tot]=-1;
		return tot++;
	}
	void init(int _n)
	{
		n=_n;
		tot=0;
		root=newnode();
	}
	void pushup(int id)
	{
		
	}
	void pushdown(int id)
	{
		if(tag[id]==-1) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=-1;
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			//do something
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	type res;
	void query(int l,int r,int &id)
	{
		if(!id) return;
		if(l>=ql&&r<=qr)
		{
			//do something
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls[id]);
		if(qr>mid) query(mid+1,r,rs[id]);
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,root);
		return res;
	}
	#undef type
};
