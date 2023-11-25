struct Segment_Tree_2D
{
	#define type int
	static const int insert_num=;
	static const int N=insert_num*20*20; //insert_num*20*log(m)
	int root[MAX<<2],tot,ls[N],rs[N],n,m;
	int ql_in,qr_in,ql_out,qr_out;
	type v[N],qv,tag[N];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		mem(root,0);
		ls[0]=rs[0]=0;
		tag[0]=0;
		v[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		tag[tot]=0;
		return tot++;
	}
	void pushup(int id)
	{
		
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=0;
	}
	void update_in(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql_in&&r<=qr_in)
		{
			v[id]+=qv;   //must update not =
			tag[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql_in<=mid) update_in(l,mid,ls[id]);
		if(qr_in>mid) update_in(mid+1,r,rs[id]);
		pushup(id);
	}
	type res_in;
	void query_in(int l,int r,int &id)
	{
		if(!id) return;
		if(l>=ql_in&&r<=qr_in)
		{
			res_in+=v[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		type res=0;
		if(ql_in<=mid) query_in(l,mid,ls[id]);
		if(qr_in>mid) query_in(mid+1,r,rs[id]);
	}
	/*************************************************/
	#define ls (id<<1)
	#define rs (id<<1|1)
	void update_out(int l,int r,int id)
	{
		update_in(1,m,root[id]);
		if(l>=ql_out&&r<=qr_out) return;
		int mid=(l+r)>>1;
		if(ql_out<=mid) update_out(l,mid,ls);
		if(qr_out>mid) update_out(mid+1,r,rs);
	}
	type res_out;
	void query_out(int l,int r,int id)
	{
		if(l>=ql_out&&r<=qr_out)
		{
			res_in=0;
			query_in(1,m,root[id]);
			res_out+=res_in;
			return;
		}
		int mid=(l+r)>>1;
		if(ql_out<=mid) query_out(l,mid,ls);
		if(qr_out>mid) query_out(mid+1,r,rs);
	}
	#undef ls
	#undef rs
	void upd(int x1,int y1,int x2,int y2,type val)
	{
		ql_out=x1;
		qr_out=x2;
		ql_in=y1;
		qr_in=y2;
		qv=val;
		update_out(1,n,1);
	}
	type ask(int x1,int y1,int x2,int y2)
	{
		ql_out=x1;
		qr_out=x2;
		ql_in=y1;
		qr_in=y2;
		res_out=0;
		query_out(1,n,1);
		return res_out;
	}
	#undef type
}tr2d;
