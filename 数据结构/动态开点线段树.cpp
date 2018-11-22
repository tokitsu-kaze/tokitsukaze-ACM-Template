//空间大小是nlogm,n为插入的节点总数,m为区间长度 
struct Segment_Tree
{
	#define type int
	int root,tot,ls[MAX*20],rs[MAX*20],ql,qr;
	type v[MAX*20],tag[MAX*20],qv;
	void init()
	{
		root=0;
		ls[0]=rs[0]=0;
		v[0]=0; 
		tag[0]=-1;
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		tag[tot]=-1;
		return tot++;
	}
	void pushdown(int id)
	{
		if(tag[id]==-1) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=-1;
	}
	void pushup(int id)
	{
		
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			v[id]=(r-l+1)*qv;
			tag[id]=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	type query(int l,int r,int &id)
	{
		if(!id) return 0;
		if(l>=ql&&r<=qr) return v[id];
		int mid=(l+r)>>1;
		type res=0;
		if(ql<=mid) res+=query(l,mid,ls[id]);
		if(qr>mid) res+=query(mid+1,r,rs[id]);
		return res;
	}
	#undef type
}tr; 
