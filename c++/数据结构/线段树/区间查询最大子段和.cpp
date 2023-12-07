struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],mx[MAX<<2],lv[MAX<<2],rv[MAX<<2],v[MAX<<2],qv;
	void pushup(int id)
	{
		mx[id]=max(mx[ls],mx[rs]);
		mx[id]=max(mx[id],rv[ls]+lv[rs]);
		lv[id]=max(lv[ls],lv[rs]+v[ls]);
		rv[id]=max(rv[rs],rv[ls]+v[rs]);
		v[id]=v[ls]+v[rs];
		lv[id]=max(lv[id],v[id]);
		rv[id]=max(rv[id],v[id]);
		mx[id]=max({mx[id],lv[id],rv[id],v[id]});
	}
	void build(int l,int r,int id)
	{
		mx[id]=lv[id]=rv[id]=-INF;
		v[id]=0;
		if(l==r)
		{
			mx[id]=lv[id]=rv[id]=v[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			mx[id]=lv[id]=rv[id]=v[id]=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res,lmx;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=max(res,mx[id]);
			res=max(res,lmx+lv[id]);
			lmx=max(lmx+v[id],rv[id]);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=-INF;
		lmx=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
