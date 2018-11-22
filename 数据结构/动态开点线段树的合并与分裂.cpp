//空间大小是nlogm,n为插入的节点总数,m为区间长度 
struct Segment_Tree
{
	#define type int
	int s[MAX*20],top;//内存池 
	int root[MAX],tot,ls[MAX*20],rs[MAX*20],ql,qr,n;
	type v[MAX*20],tag[MAX*20],qv;
	void init()
	{
		top=0;
		mem(root,0);
		ls[0]=rs[0]=0;
		v[0]=0;
		tot=1;
	}
	int newnode()
	{
		int t;
		if(top) t=s[--top];
		else t=tot++;
		ls[t]=rs[t]=0;
		v[t]=0;
		return t;
	}
	void delnode(int x)
	{
		s[top++]=x;
	}
	void pushup(int id)
	{
		v[id]=v[ls[id]]+v[rs[id]];
	}
	void pushdown(int id)
	{
		if(tag[id]==-1) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=-1;
	}
	int split(int l,int r,int &id)
	{
		if(!id) return 0;
		if(ql<=l&&r<=qr)
		{
			int temp=id;
			id=0;
			return temp;
		}
		int t=newnode();
		int mid=(l+r)>>1;
		if(ql<=mid) ls[t]=split(l,mid,ls[id]);
		if(qr>mid) rs[t]=split(mid+1,r,rs[id]);
		pushup(t);
		pushup(id);
		return t;
	}
	int merge(int a,int b)
	{
		if(!a||!b) return a+b;
		ls[a]=merge(ls[a],ls[b]);
		rs[a]=merge(rs[a],rs[b]);
		if(!ls[a]&&!rs[a])
		{
			v[a]+=v[b];//把b的信息合并给a 
		}
		else
		{
			pushup(a);
			//此处可能需要更新其他东西 
		}
		delnode(b);
		return a;
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

